
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
    
    const char* text;
} Button;


Button makeButton(const char* newText, int newX, int newY);
void drawButton(Button* b);
