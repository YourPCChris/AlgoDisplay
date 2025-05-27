
#pragma once 

#include <iostream>
#include <vector>
#include <memory>
#include <stack>
#include "gridSquare.h"


class Grid
{
    public:
        enum Algo
        {
            RANDOM,
            BF,
            DF,
            DIJKSTRA,
            NONE
        };

        Grid(unsigned short numRow, unsigned short numCol, int newSquareSize=20);
        void makeGrid();
        void drawGrid();
        void display();
        void highlightSquare(int direction);
        void highlightSquare(int x, int y, Color newColor);
        void right();
        void left();
        void up();
        void down();
        int getX();
        int getY();
        int getRow();
        int getCol();
        Algo getAlgo();
        void setX(int newX);
        void setY(int newY);
        void resetPos();
        void clearGrid();
        void setAlgo(Algo newAlgo);
        void destFound();
        void pushToStack();
        std::pair<unsigned short, unsigned short> peepStack();
        void popFromStack();
        bool checkVisited(unsigned short x, unsigned short y);
        bool checkEmpty();
        void goToDest();
        

    private:
        std::unique_ptr<GridSquare> grid[60][80];
        unsigned short row;
        unsigned short col;
        unsigned short  x;
        unsigned short y;
        int squareSize;
        Algo runningAlgo;
        std::stack<std::pair<unsigned short, unsigned short>> pathStack;
};

