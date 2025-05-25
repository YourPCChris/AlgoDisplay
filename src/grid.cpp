#include "grid.h"
#include "gridSquare.h"


//--------------------Grid______________________________
Grid::Grid(unsigned short numRow, unsigned short numCol, int newSquareSize) 
    : row(numRow), col(numCol), squareSize(newSquareSize), x(0), y(0)
{
    makeGrid();
    grid[y][x]->setColor(RED);
    //highlightSquare();
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

void Grid::highlightSquare()
{ 
    if (y >= 0 && y < row && x >=0 && x < col){
        std::cout << "Colouring in Square at : " << x << " : " << y << std::endl;
        grid[y][x]->setColor(DARKBLUE);
        return;
    }
    std::cout << " Failed to set Color -------------_" << std::endl;
}

void Grid::right()
{
    if (x+1 < col){
        std::cout << "Moving Right Values are: " << x+1 << " : " << y << std::endl;
        x++;
        highlightSquare();
    }
}
void Grid::left()
{
    if (x-1 >= 0){
        std::cout << "Moving Left Values are: " << x-1 << " : " << y << std::endl;
        x--;
        highlightSquare();
    }
}
void Grid::up()
{
    if (y-1 >= 0){
        std::cout << "Moving UP Values are: " << x << " : " << y-1 << std::endl;
        y--;
        highlightSquare();
    }
}
void Grid::down()
{
    if (y+1 < row){
        std::cout << "Moving DOWN Values are: " << x << " : " << y+1 << std::endl;
        y++;
        highlightSquare();
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

void Grid::resetPos() { x = 0; y = 0; grid[y][x]->setColor(RED);}
int Grid::getX() { return x;}
int Grid::getY() { return y;}
int Grid::getRow() { return row;}
int Grid::getCol() { return col;}
