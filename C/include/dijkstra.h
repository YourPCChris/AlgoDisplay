#pragma once

#include "nodes.h"
#include "raylib.h"
#include "queue.h"


typedef struct
{
   Node* nodes;
   int posID;
   int delay;
   int nextFree;
   int size;
} Dijkstra;

Dijkstra makeDijkstra();
void freeDijkstra(Dijkstra* d);
