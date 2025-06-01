#include "breadthFirst.h"
#include <memory>

void addNodes(std::unique_ptr<Grid>& g)
{
    if (g->queueEmpty()){
        g->setAlgo(Grid::Algo::NONE);
        std::cout << "Queue Empty Breadth First Done" << std::endl;
        return;
    }

    //Check and add right node 
    if (g->getX() + 1 < g->getCol()){
        if (!g->checkVisited(g->getX()+1, g->getY())){
            g->pushToQueue(g->getX() + 1, g->getY());
        }
    }
    //Check and add left node
    if (g->getX() - 1 >= g->getCol()){
        if (!g->checkVisited(g->getX() - 1, g->getY())){
            g->pushToQueue(g->getX()-1, g->getY());
        }
    }
    //Check and add bottom node 
    if (g->getY() + 1 < g->getRow()){
        if (!g->checkVisited(g->getX(), g->getY() + 1)){
            g->pushToQueue(g->getX(), g->getY() + 1);
        }
    }
    //Check and add top node 
    if (g->getY() - 1 >= g->getRow()){
        if (!g->checkVisited(g->getX(), g->getY() - 1)){
            g->pushToQueue(g->getX(), g->getY() - 1);
        }
    }
}

void runBreadthFirst(std::unique_ptr<Grid>& g)
{
    //Add Nodes to queue to be visited 
    addNodes(g);
    g->popFromQueue();
    std::pair<int,int> newPos = g->getFront();
    g->highlightSquare(g->getX(), g->getY(), DARKBLUE);
    g->setX(newPos.first);
    g->setY(newPos.second);
    g->highlightSquare(newPos.first, newPos.second, RED);
}
