
#pragma once 

#include <iostream>
#include <vector>
#include <memory>
#include "gridSquare.h"


class Grid
{

    //std::vector<std::unique_ptr<GridSquare>> grid;
    std::unique_ptr<GridSquare> grid[60][80];
    unsigned short row;
    unsigned short col;
    unsigned short  x;
    unsigned short y;
    int squareSize;
    
    public:
        Grid(unsigned short numRow, unsigned short numCol, int newSquareSize=20);
        void makeGrid();
        void drawGrid();
        void display();
        void highlightSquare();
        void right();
        void left();
        void up();
        void down();
        int getX();
        int getY();
        int getRow();
        int getCol();
        void resetPos();
        void clearGrid();
};

