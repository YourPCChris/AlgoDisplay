#include <stdio.h>
#include "raylib.h"
#include "window.h"
#include "button.h"



void main()
{
    printf("We Ball\n");

    Window w = {.FPS=60};
    makeWindow(&w,"Dijkstra", 1000, 800);
    addButton(&w, "Go/Stop");

    InitWindow(w.width, w.height, w.title);
    SetTargetFPS(w.FPS);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(w.color);
        displayWindow(&w);
        EndDrawing();
    }
}
