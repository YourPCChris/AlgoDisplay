
#include "dijkstra.h"
#include "raylib.h"
#include "nodes.h"
#include <stdlib.h>


Dijkstra makeDijkstra()
{
    Dijkstra d;
    d.size = 10;
    d.nodes = malloc(d.size * sizeof(Node));
    d.posID = 0;
    d.delay = 1;
    d.nextFree = 0;
    return d;
}

void freeDijkstra(Dijkstra* d)
{
    if (d->nodes != NULL){
        free(d->nodes);
        d->nodes = NULL;
    }
}


