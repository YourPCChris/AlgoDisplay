#include "grid.h"
#include "gridSquare.h"


//--------------------Grid______________________________
Grid::Grid(unsigned short numRow, unsigned short numCol, int newSquareSize) 
    : row(numRow), col(numCol), squareSize(newSquareSize), x(0), y(0)
{
    makeGrid();
    grid[y][x]->setColor(RED);
    runningAlgo = Algo::NONE;
}

void Grid::makeGrid()
{
    for (int i=0; i < row ; i++)
    {
        for (int j=0; j < col ;j++)
        {
            grid[i][j] = std::make_unique<GridSquare>(squareSize);
            //grid.push_back(std::make_unique<GridSquare>(squareSize));
        }
    }
}

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

void Grid::highlightSquare(int newX, int newY, Color newColor)
{
    if (newX >= 0 && newX < col && newY >= 0 && newY < row) {
        // Mark previous square as visited (DARKBLUE) unless it's already DARKGREEN
        if (x >= 0 && x < col && y >= 0 && y < row) {
            Color currentColor = grid[y][x]->getColor();
            if (!(currentColor.r == DARKGREEN.r && currentColor.g == DARKGREEN.g &&
                  currentColor.b == DARKGREEN.b && currentColor.a == DARKGREEN.a)) {
                grid[y][x]->setColor(DARKBLUE);
            }
        }
        // Update position and set new square to RED
        x = newX;
        y = newY;
        grid[y][x]->setColor(newColor); // Typically RED
        std::cout << "Moved to: (" << x << ", " << y << ")" << std::endl;
    } else {
        std::cout << "Invalid move to: (" << newX << ", " << newY << ")" << std::endl;
    }
}
/*
void Grid::highlightSquare(int newX, int newY, Color newColor)
{
    //Highlight current square RED
    if (newY >= 0 && newY < row && newX >=0 && newX < col){
        std::cout << "Colouring in Square at : " << x << " : " << y << std::endl;
        grid[newY][newX]->setColor(RED);

        //Highlight previous square DARKBLUE
        grid[y][x]->setColor(newColor);
    }
}

void Grid::highlightSquare(int direction)
{ 
    //Highlight current square RED
    if (y >= 0 && y < row && x >=0 && x < col){
        std::cout << "Colouring in Square at : " << x << " : " << y << std::endl;
        grid[y][x]->setColor(RED);

        //Highlight previous square DARKBLUE
        if (0 <= direction <= 4){
            switch (direction)
            {
                case 0:
                    //Right
                    grid[y][x-1]->setColor(DARKBLUE);
                    break;
                case 1:
                    //Left
                    grid[y][x+1]->setColor(DARKBLUE);
                    break;
                case 2: //Up
                    grid[y+1][x]->setColor(DARKBLUE);
                    break;
                case 3:
                    //Down
                    grid[y-1][x]->setColor(DARKBLUE);
                    break;
                default:
                    std::cout << "Invalid direction given, previous square not coloured" << std::endl;
            }
        return;
        }
    }
    std::cout << " Failed to set Color -------------_" << std::endl;
}
*/

void Grid::right()
{
    if (x+1 < col){
        //std::cout << "Moving Right Values are: " << x+1 << " : " << y << std::endl;
        highlightSquare(x+1, y, RED);
    }
}
void Grid::left()
{
    if (x-1 >= 0){
        //std::cout << "Moving Left Values are: " << x-1 << " : " << y << std::endl;
        highlightSquare(x-1, y, RED);
    }
}
void Grid::up()
{
    if (y-1 >= 0){
        //std::cout << "Moving UP Values are: " << x << " : " << y-1 << std::endl;
        highlightSquare(x, y-1, RED);
    }
}
void Grid::down()
{
    if (y+1 < row){
        //std::cout << "Moving DOWN Values are: " << x << " : " << y+1 << std::endl;
        highlightSquare(x, y+1, RED);
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

    return isDarkGreen || isDarkBlue;
}
        

void Grid::pushToStack() 
{ 
    std::pair<unsigned short, unsigned short> posToPush = std::make_pair(x,y);
    pathStack.push(posToPush);
}

void Grid::popFromStack()
{
    if (!pathStack.empty())
        pathStack.pop();
}
void Grid::setAlgo(Grid::Algo newAlgo) { runningAlgo = newAlgo;}
void Grid::resetPos() { x = 0; y = 0; grid[y][x]->setColor(RED);}
std::pair<unsigned short, unsigned short> Grid::peepStack() {return pathStack.top();}

bool Grid::checkEmpty() { return pathStack.empty();}
int Grid::getX() { return x;}
int Grid::getY() { return y;}
int Grid::getRow() { return row;}
int Grid::getCol() { return col;}
void Grid::setX(int newX) { x = newX;}
void Grid::setY(int newY) { y = newY;}
Grid::Algo Grid::getAlgo() { return runningAlgo;}
void Grid::goToDest() { x = col-1; y = row-1; destFound();}
