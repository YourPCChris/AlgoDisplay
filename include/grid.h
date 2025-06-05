
#pragma once 

#include <iostream>
#include <vector>
#include <memory>
#include <stack>
#include <queue>
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
        int getDirection();
        Algo getAlgo();
        void setX(int newX);
        void setY(int newY);
        void resetPos();
        void clearGrid();
        void setAlgo(Algo newAlgo);
        void destFound();
        bool checkVisited(unsigned short x, unsigned short y);
        void goToDest();
	void resetAlgos();
        //-------------------Stack------------------------------
        bool checkStackEmpty();
        void popFromStack();
        std::pair<int,int> peepStack();
        void pushToStack();
        void emptyStack();
        //-------------------Queue------------------------------
        bool queueEmpty();
        void pushToQueue(int x, int y);
        std::pair<int,int> getFront();
        void popFromQueue();
        void emptyQueue();
        

    private:
        std::unique_ptr<GridSquare> grid[60][80];
        unsigned short row;
        unsigned short col;
        unsigned short  x;
        unsigned short y;
        int squareSize;
        int direction;
        Algo runningAlgo;
        std::stack<std::pair<int,int>> pathStack;
        std::queue<std::pair<int,int>> queue;
};

