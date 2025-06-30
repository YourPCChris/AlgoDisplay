
#include "Button.h"
#include "raylib.h"

//-------------------------Button___________________________
Button::Button(const char* newText, float newX, float newY, float newWidth, float newHeight)
:text(newText), x(newX), y(newY), width(newWidth), height(newHeight), color(DARKGRAY)
{
    rec = std::make_unique<Rectangle>(Rectangle{x, y, width, height});
}

void Button::display()
{
    DrawRectangleRec(*rec, DARKGRAY);
    DrawText(text, x+width*0.125, y+height/4, height*0.33, BLACK);
}

float Button::getHeight() { return height;}   
Rectangle Button::getRec() { return *rec;}
