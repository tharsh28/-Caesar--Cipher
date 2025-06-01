#ifndef QUEUE_H
#define QUEUE_H

#define SIZE 26

typedef struct {
    char data[SIZE];
    int front;
    int rear;
    int count;
} CircularQueue;

void initQueue(CircularQueue *q);
void enqueue(CircularQueue *q, char item);
char dequeue(CircularQueue *q);
char getShiftedChar(CircularQueue *q, char ch, int shift);

#endif

