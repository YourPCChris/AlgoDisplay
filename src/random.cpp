#include "random.h"
#include <grid.h> 
#include <iostream>
#include <random>
#include <ctime>


int getRandomNum()
{
    static std::mt19937 gen(static_cast<unsigned short>(time(nullptr)));
    std::uniform_int_distribution<> distrib(1, 4);

    int randNum = distrib(gen);
    return randNum;
}

void runRandom(std::unique_ptr<Grid>& g)
{
    //Backtrack if stuck
    if (g->checkVisited(g->getX()+1, g->getY()) && 
            g->checkVisited(g->getX()-1, g->getY()) &&
            g->checkVisited(g->getX(), g->getY()-1) &&
            g->checkVisited(g->getX(), g->getY()+1)){

        std::pair<int,int> newPos = g->peepStack();
        g->highlightSquare(g->getX(), g->getY(), DARKGREEN);
        g->setX(newPos.first);
        g->setY(newPos.second);
        g->popFromStack();
        g->highlightSquare(g->getX(), g->getY(), RED);
        return;
    }

    //Get random direction and alter the x&y values to reflect that 
    int direction = getRandomNum();

    switch(direction)
    {
        case 1:
            if (!(g->getX() + 1 == g->getCol())){
                if (!g->checkVisited(g->getX()+1, g->getY())){
                    g->pushToStack();
                    g->right(); 
                }
                //std::cout << "RIGHT" << std::endl;
            }
            break;
        case 2:
            if (!g->checkVisited(g->getX()-1, g->getY())){
                g->pushToStack();
                g->left();
            }
            //std::cout << "LEFT" << std::endl;
            break;
        case 3:
            if (!g->checkVisited(g->getX(), g->getY()-1)){
                g->pushToStack();
                g->up();
            }
            //std::cout << "UP" << std::endl;
            break;
        case 4:
            if (!(g->getY() + 1 == g->getRow())){
                if (!g->checkVisited(g->getX(), g->getY()+1)){
                    g->pushToStack();
                    g->down();
                }
                //std::cout << "DOWN" << std::endl;
            }
            break;
        default:
            std::cout << "Not a direction" << std::endl;
    }
}
