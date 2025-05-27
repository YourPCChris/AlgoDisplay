
#include <stack>
#include <memory>
#include "depthFirst.h"


void backTrack(std::unique_ptr<Grid>& g)
{
    if (g->checkEmpty()){
        g->setAlgo(Grid::Algo::NONE);
        std::cout << "Stack Empty" << std::endl;
        return;
    }

    std::pair<unsigned short, unsigned short> newPos = g->peepStack();
    g->highlightSquare(g->getX(), g->getY(), DARKGREEN);
    g->setX(newPos.first);
    g->setY(newPos.second);
    g->popFromStack();
    g->highlightSquare(newPos.first, newPos.second, RED);
}

void runDepthFirst(std::unique_ptr<Grid>& g)
{
    //Direction Order {Right-Up-Left-Down}
    //Check for unvisited square (DARKGRAY) if it is inbounds go there if all options are exausted backtrack using stack
    //Right
    if (g->getX()+1 < g->getCol()){
        if (!g->checkVisited(g->getX()+1, g->getY())){
            g->pushToStack();
            g->right();
            return;
        }
    }
    //Down
    if (g->getY()+1 < g->getRow()){
        if (!g->checkVisited(g->getX(), g->getY()+1)){
            g->pushToStack();
            g->down();
            return;
        }
    }
    //Left
    if (g->getX()-1 >= 0){
        if (!g->checkVisited(g->getX()-1, g->getY())){
            g->pushToStack();
            g->left();
            return;
        }
    }
    //Up
    if (g->getY()-1 >= 0){
        if (!g->checkVisited(g->getX(), g->getY()-1)){
            g->pushToStack();
            g->up();
            return;
        }
    }
        //All neighbours are visited so backtrack
    backTrack(g);
}

