
#include <iostream>
#include "grid.h"
#include "Button.h"
#include "random.h"
#include "raylib.h"


std::vector<std::unique_ptr<Button>> getButtons()
{
    std::vector<std::unique_ptr<Button>> buttons;

    buttons.push_back(std::make_unique<Button>("Clear Grid", 20, 20));
    buttons.push_back(std::make_unique<Button>("Reset Position", 20, buttons[0]->getHeight()*2));
    buttons.push_back(std::make_unique<Button>("Random", 20, buttons[0]->getHeight()*4));
    buttons.push_back(std::make_unique<Button>("Dijkstra's", 20, buttons[0]->getHeight()*6));

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
                std::cout << "Random Algo with two recs" << std::endl;
                runRandom(g);
            }else if (CheckCollisionRecs(mouseRec, buttons[3]->getRec())){
                std::cout << "Dijkstra's Algorithm" << std::endl;
            }
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

            
