#include "grid.h"
#include "gridSquare.h"
#include <cstring>
#include <random>


//--------------------Grid______________________________
Grid::Grid(unsigned short numRow, unsigned short numCol, int newSquareSize) 
    : row(numRow), col(numCol), squareSize(newSquareSize), x(0), y(0)
{
    makeGrid();
    grid[y][x]->setColor(RED);
    runningAlgo = Algo::NONE;
    direction = 0;
    std::pair<int,int> start = std::make_pair<int,int>(0,0);
    queue.push(start);
    errorText = "";
}

void Grid::makeGrid()
{
    for (int i=0; i < row ; i++)
    {
        for (int j=0; j < col ;j++)
        {
            grid[i][j] = std::make_unique<GridSquare>(squareSize);
        }
    }
}

void Grid::makeMaze()
{}

void Grid::display()
{
    int startX = 200;
    int startY = 20;
    int drawX=startX, drawY=startY;
    
    for (int i=0; i < row ; i++)
    {
        for (int j=0; j < col ; j++)
        {
            drawX += squareSize + 2;
            grid[i][j]->draw(drawX, drawY);
        }
        drawY += squareSize + 2;
        drawX = startX;
    }
} 

void Grid::highlightSingleSquare(int newX, int newY, Color newColor)
{
    if (newX >= 0 && newX < col && newY >= 0 && newY < row) {
        grid[newY][newX]->setColor(newColor);
    }
}

void Grid::highlightSquare(int newX, int newY, Color newColor)
{
    if (newX >= 0 && newX < col && newY >= 0 && newY < row) {
        // Mark previous square as visited (DARKBLUE) unless it's already DARKGREEN
        if (x >= 0 && x < col && y >= 0 && y < row) {
            Color currentColor = grid[y][x]->getColor();
            if (!(currentColor.r == DARKGREEN.r && currentColor.g == DARKGREEN.g &&
                  currentColor.b == DARKGREEN.b && currentColor.a == DARKGREEN.a) &&
                    !(currentColor.r == ORANGE.r && currentColor.g == ORANGE.g &&
                        currentColor.b == ORANGE.b && currentColor.a == ORANGE.a)) {
                grid[y][x]->setColor(DARKBLUE);
            }
        }
        // Update position and set new square to newColor
        x = newX;
        y = newY;
        grid[y][x]->setColor(newColor); 
    } else {
        static std::string stringError = "Invalid Move -> " + std::to_string(newX) + ":" + std::to_string(newY);
        setErrorText(stringError.c_str());
        //std::cout << "Invalid move to: (" << newX << ", " << newY << ")" << std::endl;
    }
}

void Grid::right()
{
    if (x+1 < col){
        //std::cout << "Moving Right Values are: " << x+1 << " : " << y << std::endl;
        highlightSquare(x+1, y, RED);
        direction = 3;
    }
}
void Grid::left()
{
    if (x-1 >= 0){
        //std::cout << "Moving Left Values are: " << x-1 << " : " << y << std::endl;
        highlightSquare(x-1, y, RED);
        direction = 1;
    }
}
void Grid::up()
{
    if (y-1 >= 0){
        //std::cout << "Moving UP Values are: " << x << " : " << y-1 << std::endl;
        highlightSquare(x, y-1, RED);
        direction = 2;
    }
}
void Grid::down()
{
    if (y+1 < row){
        //std::cout << "Moving DOWN Values are: " << x << " : " << y+1 << std::endl;
        highlightSquare(x, y+1, RED);
        direction = 0;
    }
}

void Grid::clearGrid()
{
    for (int i=0; i < row ; i++)
    {
        for (int j=0; j < col ; j++)
        {
            grid[i][j]->setColor(GRAY);
        }
    }
}

void Grid::destFound()
{
    GridSquare* dest = grid[row-1][col-1].get();
    Color dColor = dest->getColor();

    if (dColor.r == RED.r && dColor.g == RED.g 
            && dColor.b == RED.b && dColor.a == RED.a){
        dest->setColor(RED);
        if (!queue.empty()){ emptyQueue();}
        if (!pathStack.empty()){ emptyStack();}
        setErrorText("Destination Found");
        runningAlgo = Grid::NONE;
    }
}

bool Grid::checkVisited(unsigned short x, unsigned short y)
{
    if (x >= col || y >= row) return true;

    Color squareColor = grid[y][x]->getColor();

    bool isDarkBlue = squareColor.r == DARKBLUE.r && squareColor.g == DARKBLUE.g
        && squareColor.b == DARKBLUE.b && squareColor.a == DARKBLUE.a;

    bool isDarkGreen = squareColor.r == DARKGREEN.r && squareColor.g == DARKGREEN.g
        && squareColor.b == DARKGREEN.b && squareColor.a == DARKGREEN.a;

    bool isOrange = squareColor.r == ORANGE.r && squareColor.g == ORANGE.g 
        && squareColor.b == ORANGE.b && squareColor.a == ORANGE.a;


    return isDarkGreen || isDarkBlue || isOrange;
}

void Grid::resetAlgos()
{
	emptyStack();
	emptyQueue();
	if (!queue.empty()){
		if (queue.front() == std::make_pair(0,0)){
			emptyQueue();
		}
	}

	if (!pathStack.empty()){
		emptyStack();
	}

	/*
	std::queue<std::pair<int,int>> tempQ = queue;
	std::stack<std::pair<int,int>> tempS = pathStack;
	//Ouput Queue contents
	std::cout << "Queue: " << std::endl;
	while(!tempQ.empty()) 
	{
		std::cout<<tempQ.front().first<<":"<<tempQ.front().second<< std::endl;
		tempQ.pop();
	}
	//Output Stack contents
	std::cout << "Stack: " << std::endl;
	while(!tempS.empty())
	{
		std::cout<<tempS.top().first<<":"<<tempS.top().second<<std::endl;
		tempS.pop();
	}
	*/
}

void Grid::addObsticals()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist_x(1,79);
    std::uniform_int_distribution<> dist_y(1,59);

    for (int i=0; i<100 ;i++)
    {
        int obstX = dist_x(gen);
        int obstY = dist_y(gen);
        if (!checkVisited(obstX,obstY)) highlightSingleSquare(obstX, obstY, ORANGE);
    }
    //std::cout << "Obstical (X:Y) -> " << obstX << ":" << obstY << std::endl;
}

void Grid::setErrorText(const char* newError) { errorText = newError;}
void Grid::setAlgo(Grid::Algo newAlgo) { runningAlgo = newAlgo;}
void Grid::resetPos() { x = 0; y = 0; grid[y][x]->setColor(RED);}
const char* Grid::getErrorText() { return errorText;}
int Grid::getX() { return x;}
int Grid::getY() { return y;}
int Grid::getRow() { return row;}
int Grid::getCol() { return col;}
int Grid::getDirection() { return direction;}
void Grid::setX(int newX) { x = newX;}
void Grid::setY(int newY) { y = newY;}
Grid::Algo Grid::getAlgo() { return runningAlgo;}
void Grid::goToDest() { x = col-1; y = row-1; destFound();}      

//---------------------Stack-------------------------
void Grid::pushToStack() 
{ 
    std::pair<int, int> posToPush = std::make_pair(x,y);
    pathStack.push(posToPush);
}

void Grid::popFromStack()
{
    if (!pathStack.empty())
        pathStack.pop();
}

void Grid::emptyStack() { while (!pathStack.empty()) { pathStack.pop();}}
std::pair<int, int> Grid::peepStack() {return (!pathStack.empty()) ? pathStack.top() : std::make_pair(-1,-1);}
bool Grid::checkStackEmpty() { return pathStack.empty();}

//---------------------Queue--------------------------
void Grid::pushToQueue(int x, int y)
{
    if (0 <= x && x < col &&
            0 <= y && y < row){
        int newX = x; int newY = y;
        std::pair<int,int> newPos = std::make_pair(x,y);
        queue.push(newPos);
    }
}

void Grid::popFromQueue()
{
    if (!queue.empty()) queue.pop();
}

std::pair<int,int> Grid::getFront()
{
    std::pair<int,int> front = (!queue.empty()) ? queue.front() : std::make_pair(-1,-1);
    return front;
}
bool Grid::queueEmpty() { return queue.empty();}
void Grid::emptyQueue() 
{
    while (!queue.empty()) { queue.pop();}
    std::pair<int, int> startPos = std::make_pair(0,0);
    queue.push(startPos);
}
