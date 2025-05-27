
#include <iostream>
#include "grid.h"
#include "Button.h"
#include "random.h"
#include "depthFirst.h"
#include "raylib.h"


std::vector<std::unique_ptr<Button>> getButtons()
{
    std::vector<std::unique_ptr<Button>> buttons;

    buttons.push_back(std::make_unique<Button>("Clear Grid", 20, 10));
    buttons.push_back(std::make_unique<Button>("Reset Position", 20, buttons[0]->getHeight()*1.2));
    buttons.push_back(std::make_unique<Button>("Random", 20, buttons[0]->getHeight()*2.4));
    buttons.push_back(std::make_unique<Button>("Dijkstra's", 20, buttons[0]->getHeight()*3.6));
    buttons.push_back(std::make_unique<Button>("Depth First", 20, buttons[0]->getHeight()*4.8));
    buttons.push_back(std::make_unique<Button>("Bredth First", 20, buttons[0]->getHeight()*6));
    buttons.push_back(std::make_unique<Button>("Go To End", 20, buttons[0]->getHeight()*7.2));

    return buttons;
}

    


int main()
{
    int windowWidth = 1200;
    int windowHeight = 800;
    InitWindow(windowWidth, windowHeight,"Algo Visulization");
    SetTargetFPS(60);
    std::unique_ptr<Grid> g = std::make_unique<Grid>(60, 80, 10);
    std::vector<std::unique_ptr<Button>> buttons = getButtons();


    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        if (g->getX() == g->getCol()-1 && g->getY() == g->getRow()-1) {
            g->destFound();
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            Rectangle mouseRec= Rectangle{(float)GetMouseX(), (float)GetMouseY(), 20, 20};
            Vector2 mousePos = Vector2{(float)GetMouseX(), (float)GetMouseY()};
            std::cout << mousePos.x << std::endl;
            std::cout << mousePos.y << std::endl;
            if (CheckCollisionRecs(mouseRec, buttons[0]->getRec())){
                g->clearGrid();
            }else if (CheckCollisionRecs(mouseRec, buttons[1]->getRec())){
                g->resetPos();
            }else if (CheckCollisionRecs(mouseRec, buttons[2]->getRec())){
                g->setAlgo(g->Algo::RANDOM);
            }else if (CheckCollisionRecs(mouseRec, buttons[3]->getRec())){
                std::cout << "Dijkstra's Algorithm" << std::endl;
                g->setAlgo(g->Algo::DIJKSTRA);
            }else if (CheckCollisionRecs(mouseRec, buttons[4]->getRec())){
                g->setAlgo(g->Algo::DF);
            }else if (CheckCollisionRecs(mouseRec, buttons[5]->getRec())){
                g->setAlgo(g->Algo::BF);
            }else if (CheckCollisionRecs(mouseRec, buttons[6]->getRec())){
                g->goToDest();
            }
        }

        switch (g->getAlgo())
        {
            case Grid::RANDOM: 
                runRandom(g);
                break;
            case Grid::BF:
                std::cout << "Breadth First Search" << std::endl;
                break;
            case Grid::DF:
                std::cout << "Depth First Search" << std::endl;
                runDepthFirst(g);
                break;
            case Grid::DIJKSTRA:
                std::cout << "Dijkra's Algorithm" << std::endl;
                break;
            case Grid::NONE:
                break;
            default:
                std::cout << "Invalid Algorithm" << std::endl;
                break;
        }
        for (auto& button : buttons)
        {
            button->display();
        }
        g->display();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

            
