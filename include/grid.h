
#pragma once 

#include <iostream>
#include <vector>
#include <memory>
#include "gridSquare.h"


class Grid
{
    public:
        enum Algo
        {
            RANDOM = 0,
            BF = 1,
            DF = 2,
            DIJKSTRA = 3,
            NONE = 4
        };

        Grid(unsigned short numRow, unsigned short numCol, int newSquareSize=20);
        void makeGrid();
        void drawGrid();
        void display();
        void highlightSquare(int direction);
        void right();
        void left();
        void up();
        void down();
        int getX();
        int getY();
        int getRow();
        int getCol();
        Algo getAlgo();
        void resetPos();
        void clearGrid();
        void setAlgo(Algo newAlgo);
        

    private:
        std::unique_ptr<GridSquare> grid[60][80];
        unsigned short row;
        unsigned short col;
        unsigned short  x;
        unsigned short y;
        int squareSize;
        Algo runningAlgo;
};

