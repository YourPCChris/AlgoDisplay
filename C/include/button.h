
#pragma once

#include <stdio.h>
#include "raylib.h"


typedef struct 
{
    int
        width,
        height,
        x,
        y,
        fontSize;
    Color color;
    Color fontColor;
    Rectangle rec;
    bool active;
    
    const char* text;
} Button;


Button makeButton(const char* newText, int newX, int newY);
void drawButton(Button* b);
void updateButton(Button* b);
void clickButton(Button* b);
