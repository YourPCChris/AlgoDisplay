#pragma once
#include <iostream>
#include "raylib.h"

class GridSquare
{
    int size;
    Color color;

    public:
        GridSquare(int newSize=10, Color newColor=GRAY);
        void highlight();
        void draw(int x, int y);
        void setColor(Color newColor);
};
