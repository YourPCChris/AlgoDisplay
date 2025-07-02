#pragma once

#include <raylib.h>
#include "button.h"


typedef struct
{
    Vector2 pos;
    float radius;
    Color color;
    int dist;
    int id;
    bool visited;
} Node;

Node makeNode();
void drawNode(Node* n);
