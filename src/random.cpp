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
    //Get random direction and alter the x&y values to reflect that 
    int direction = getRandomNum();

    switch(direction)
    {
        case 1:
            if (!(g->getX() + 1 == g->getCol())){
                g->right();
                //std::cout << "RIGHT" << std::endl;
            }
            break;
        case 2:
            g->left();
            //std::cout << "LEFT" << std::endl;
            break;
        case 3:
            g->up();
            //std::cout << "UP" << std::endl;
            break;
        case 4:
            if (!(g->getY() + 1 == g->getRow())){
                g->down();
                //std::cout << "DOWN" << std::endl;
            }
            break;
        default:
            std::cout << "Not a direction" << std::endl;
    }
}
