
#include <stdio.h>
#include "raylib.h"
#include "button.h"

Button makeButton(const char* newText, int newX, int newY)
{
    Button b;
    b.active = false;
    b.text = newText;
    b.x = newX;
    b.y = newY;
    b.width = 50;
    b.height = 50;
    b.fontSize = 10;
    b.color = BLACK;
    b.fontColor = WHITE;
    b.rec = (Rectangle){newX, newY, b.width, b.height};

    return b;
}

void drawButton(Button* b)
{
    DrawRectangle(b->x, b->y, b->width, b->height, b->color);
    DrawText(b->text, b->x + b->width/16, (b->y + b->height/2), b->fontSize, b->fontColor);
}

void updateButton(Button* b)
{
    clickButton(b);
}

void clickButton(Button* b)
{
    (b->active) ? (b->color = BLACK) : (b->color = BLUE);
    b->active = !b->active;
}
