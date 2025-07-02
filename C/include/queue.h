#pragma once



typedef struct 
{
    int
        head,
        tail,
        size,
        max;
    void** arr;
} Queue;

Queue makeQueue(int size);
void enqueue(Queue* q, void* node);
void* dequeue(Queue* q);
void* frontQueue(Queue* q);
int queueEmpty(Queue* q);
int queueFull(Queue* q);
void freeQueue(Queue* q);

