#include <stdio.h>
#include "raylib.h"
#include "window.h"
#include "button.h"



void main()
{
    printf("We Ball\n");

    Window w;
    makeWindow(&w,"Dijkstra", 1000, 800);

    InitWindow(w.width, w.height, w.title);
    SetTargetFPS(w.FPS);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(w.color);
        EndDrawing();
    }
}
