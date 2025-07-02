
#include <stdlib.h>
#include "raylib.h"
#include "queue.h"
#include "nodes.h"


Queue makeQueue(int size)
{
    Queue q;
    q.arr = malloc(sizeof(void*) * size);
    q.head = 0;
    q.tail = 0;
    q.size = 0;
    q.max = size;

    return q;
}

void enqueue(Queue* q, void* node)
{
    if (!q) return;
    if (!node) return;
    if (queueFull(q) == 1) return;

    q->arr[q->tail] = node;
    q->tail = (q->tail + 1) % q->max;
    q->size++;
}

void* dequeue(Queue* q)
{
    if(!q) return NULL;

    if (queueEmpty(q) == 1) return NULL;
    void* node = q->arr[q->head];
    q->head = (q->head + 1) % q->max;
    q->size--;

    return node;
}

void* frontQueue(Queue* q)
{
    if (queueEmpty(q) == 1)
        return NULL;
    return q->arr[q->head];
}

int queueEmpty(Queue* q)
{
    if (q->size == 0) return 1;
    return -1;
}

int queueFull(Queue* q)
{
    if (q->size == q->max) return 1;
    return -1;
}

void freeQueue(Queue* q)
{
    for (int i=0; i < q->size ;i++)
    {
        free(q->arr[i]);
    }
    free(q->arr);
    free(q);
}

    
