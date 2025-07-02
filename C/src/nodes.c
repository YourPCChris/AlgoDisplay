
#include "nodes.h"
#include "raylib.h"
#include "dijkstra.h"


Node makeNode(int newID)
{
    Node n;
    n.pos = (Vector2){GetScreenWidth()/2 + 30, GetScreenHeight()/2};
    n.radius = 10;
    n.color = DARKBLUE;
    n.dist = -1;
    n.id = newID;
    n.visited = false;

    return n;
}

void drawNode(Node* n)
{
    DrawCircle(n->pos.x, n->pos.y, n->radius, n->color);
}
