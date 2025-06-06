#include "breadthFirst.h"
#include <memory>


void addNodes(std::unique_ptr<Grid>& g)
{
    if (g->queueEmpty()){
        g->setAlgo(Grid::Algo::NONE);
        g->emptyQueue();
        std::cout << "Queue Empty Breadth First Done" << std::endl;
        const char* error = "Queue Empty Breadth First Done";
        g->setErrorText(error);
        return;
    }

    int x = g->getX();
    int y = g->getY();


    //Check and add right node 
    if (x + 1 < g->getCol()){
        if (!g->checkVisited(x+1, y)){
            g->pushToQueue(x + 1, y);
            g->highlightSquare(x+1, y, DARKBLUE);
        }
    }
    //Check and add left node
    if (x - 1 >= 0){
        if (!g->checkVisited(x - 1, y)){
            g->pushToQueue(x-1, g->getY());
            g->highlightSquare(x-1, y, DARKBLUE);
        }
    }
    //Check and add bottom node 
    if (y+1 < g->getRow()){
        if (!g->checkVisited(x, y + 1)){
            g->pushToQueue(x, y + 1);
            g->highlightSquare(x, y+1, DARKBLUE);
        }
    }
    //Check and add top node 
    if (y - 1 >= 0){
        if (!g->checkVisited(x, y - 1)){
            g->pushToQueue(x, y - 1);
            g->highlightSquare(x, y-1, DARKBLUE);
        }
    }
}

void runBreadthFirst(std::unique_ptr<Grid>& g)
{
    //Check if at Destination
    if (g->getX() == g->getCol() - 1 &&
            g->getY() == g->getRow() - 1){
        g->setAlgo(Grid::Algo::NONE);
        g->emptyQueue();
        std::cout << "Destination Found" << std::endl;
        const char* error = "Destination Found";
        g->setErrorText(error);
        return;
    }

    //Add Nodes to queue to be visited 
    addNodes(g);

    g->popFromQueue();
    std::pair<int,int> newPos = g->getFront();
    if (newPos == std::make_pair(-1,-1)) return;
    g->highlightSquare(g->getX(), g->getY(), DARKBLUE);
    g->setX(newPos.first);
    g->setY(newPos.second);
    g->highlightSquare(newPos.first, newPos.second, RED);
}
