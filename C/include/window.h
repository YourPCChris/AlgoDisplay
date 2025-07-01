
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "button.h"


typedef struct
{
    int
        width,
        height;
    const int FPS;
    const char* title;
    Color color;
    Button* buttons;
    unsigned int size;
    unsigned int nextFree;
    double spacing;
} Window;


void makeWindow(Window* w, const char* newTitle, int newWidth, int newHeight);
void addButton(Window* w, const char* newString);
void displayWindow(Window* w);
void freeWindow(Window* w);
