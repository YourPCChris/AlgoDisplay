#include "gridSquare.h"
#include "raylib.h"

//------------------------------GridSquare__________________
GridSquare::GridSquare(int newSize, Color newColor) : size(newSize), color(newColor) {}
void GridSquare::draw(int x, int y)
{
    DrawRectangle(x, y, size, size, color);
}

void GridSquare::setColor(Color newColor) { color = newColor;}


