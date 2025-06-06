
#include <iostream>
#include <cstring>
#include "grid.h"
#include "Button.h"
#include "random.h"
#include "depthFirst.h"
#include "breadthFirst.h"
#include "raylib.h"


std::vector<std::unique_ptr<Button>> getButtons()
{
    std::vector<std::unique_ptr<Button>> buttons;

    buttons.push_back(std::make_unique<Button>("Clear Grid", 25, 20));
    buttons.push_back(std::make_unique<Button>("Reset Position", 25, buttons[0]->getHeight()*2.7));
    buttons.push_back(std::make_unique<Button>("Reset Algorithms", 25, buttons[0]->getHeight()*1.5));
    buttons.push_back(std::make_unique<Button>("Add Obsticals", 25, buttons[0]->getHeight()*3.9));
    buttons.push_back(std::make_unique<Button>("Random", 25, buttons[0]->getHeight()*5.1));
    buttons.push_back(std::make_unique<Button>("Dijkstra's", 25, buttons[0]->getHeight()*6.3));
    buttons.push_back(std::make_unique<Button>("Depth First", 25, buttons[0]->getHeight()*7.5));
    buttons.push_back(std::make_unique<Button>("Breadth First", 25, buttons[0]->getHeight()*8.7));
    buttons.push_back(std::make_unique<Button>("Go To End", 25, buttons[0]->getHeight()*9.9));
    return buttons;
}

    


int main()
{
    int windowWidth = 1200;
    int windowHeight = 800;
    InitWindow(windowWidth, windowHeight,"Algo Visulisation");
    SetTargetFPS(60);
    std::unique_ptr<Grid> g = std::make_unique<Grid>(60, 80, 10);
    std::vector<std::unique_ptr<Button>> buttons = getButtons();


    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        if (g->getX() == g->getCol()-1 && g->getY() == g->getRow()-1) {
            g->destFound();
        }else if (std::strcmp(g->getErrorText(), "Destination Found") == 0) {
            std::cout << "Clearing Error Message" << std::endl;
            g->setErrorText(" ");
        }

        //If button pressed set algorithm, if algo already running pause it(set algo to NONE)
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            Rectangle mouseRec= Rectangle{(float)GetMouseX(), (float)GetMouseY(), 20, 20};
            Vector2 mousePos = Vector2{(float)GetMouseX(), (float)GetMouseY()};
            //std::cout << mousePos.x << std::endl;
            //std::cout << mousePos.y << std::endl;
            if (CheckCollisionRecs(mouseRec, buttons[0]->getRec())){
                g->clearGrid();
            }else if (CheckCollisionRecs(mouseRec, buttons[1]->getRec())){
                g->resetPos();
            }else if (CheckCollisionRecs(mouseRec, buttons[2]->getRec())){
		    g->resetAlgos();
            }else if (CheckCollisionRecs(mouseRec, buttons[3]->getRec())){
                g->addObsticals();
            }else if (CheckCollisionRecs(mouseRec, buttons[4]->getRec())){
                if (g->getAlgo() != g->Algo::RANDOM){g->setAlgo(g->Algo::RANDOM);}
                else{g->setAlgo(g->Algo::NONE);}
            }else if (CheckCollisionRecs(mouseRec, buttons[5]->getRec())){
                std::cout << "Dijkstra's Algorithm" << std::endl;
                if (g->getAlgo() != g->Algo::DIJKSTRA){g->setAlgo(g->Algo::DIJKSTRA);}
                else{g->setAlgo(g->Algo::NONE);}
            }else if (CheckCollisionRecs(mouseRec, buttons[6]->getRec())){
                if (g->getAlgo() != g->Algo::DF){g->setAlgo(g->Algo::DF);}
                else{g->setAlgo(g->Algo::NONE);}
            }else if (CheckCollisionRecs(mouseRec, buttons[7]->getRec())){
                if (g->getAlgo() != g->Algo::BF){g->setAlgo(g->Algo::BF);}
                else{g->setAlgo(g->Algo::NONE);}
            }else if (CheckCollisionRecs(mouseRec, buttons[8]->getRec())){ 
                g->goToDest();
            }
        }

        switch (g->getAlgo())
        {
            case Grid::RANDOM: 
                runRandom(g);
                break;
            case Grid::BF:
                runBreadthFirst(g);
                break;
            case Grid::DF:
                runDepthFirst(g);
                break;
            case Grid::DIJKSTRA:
                break;
            case Grid::NONE:
                break;
            default:
                std::cout << "Invalid Algorithm" << std::endl;
                break;
        }
        //Draw Buttons
        for (auto& button : buttons)
        {
            button->display();
        }
        //Draw Error Label
        DrawText(g->getErrorText(), 25, GetScreenHeight()-20, 20, RED);
        g->display();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
