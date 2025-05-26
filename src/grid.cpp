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

void Grid::right()
{
    if (x+1 < col){
        std::cout << "Moving Right Values are: " << x+1 << " : " << y << std::endl;
        x++;
        highlightSquare(0);
    }
}
void Grid::left()
{
    if (x-1 >= 0){
        std::cout << "Moving Left Values are: " << x-1 << " : " << y << std::endl;
        x--;
        highlightSquare(1);
    }
}
void Grid::up()
{
    if (y-1 >= 0){
        std::cout << "Moving UP Values are: " << x << " : " << y-1 << std::endl;
        y--;
        highlightSquare(2);
    }
}
void Grid::down()
{
    if (y+1 < row){
        std::cout << "Moving DOWN Values are: " << x << " : " << y+1 << std::endl;
        y++;
        highlightSquare(3);
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

void Grid::setAlgo(Grid::Algo newAlgo) { runningAlgo = newAlgo;}
void Grid::resetPos() { x = 0; y = 0; grid[y][x]->setColor(RED);}
int Grid::getX() { return x;}
int Grid::getY() { return y;}
int Grid::getRow() { return row;}
int Grid::getCol() { return col;}
Grid::Algo Grid::getAlgo() { return runningAlgo;}
