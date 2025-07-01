
#include <stdio.h>
#include "raylib.h"
#include "button.h"

Button makeButton(const char* newText, int newX, int newY)
{
    Button b;
    b.text = newText;
    b.x = newX;
    b.y = newY;
    b.fontSize = 10;
    b.color = BLACK;
    b.fontColor = WHITE;

    return b;
}

void drawButton(Button* b)
{
    DrawRectangle(b->x, b->y, b->width, b->height, b->color);
    DrawText(b->text, b->x, b->y, b->fontSize, b->fontColor);
}

