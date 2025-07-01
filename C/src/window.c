#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "window.h"
#include "button.h"


 void makeWindow(Window* w, const char* newTitle, int newWidth, int newHeight)
{
     w->width = newWidth;
     w->height = newHeight;
     w->title = newTitle;
     w->nextFree = 0;
     w->spacing = 1.2;
     w->color = RAYWHITE;
     w->size = 5;
     w->buttons = malloc(w->size*sizeof(Button));
}
 
void addButton(Window* w, const char* newString)
{
    if (!w) return;
    w->buttons[w->nextFree] = makeButton(newString, 25, 25+(w->spacing * w->nextFree));
    w->nextFree++;
}

void displayWindow(Window* w)
{
    if(!w) printf("Error Allocating Window");

    for (int i=0; i < w->size ; i++)
    {
        drawButton(&(w->buttons[i]));
    }
}



