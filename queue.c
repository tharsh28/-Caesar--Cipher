#include "queue.h"

void initQueue(CircularQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
    for (char c = 'A'; c <= 'Z'; c++) {
        enqueue(q, c);
    }
}

void enqueue(CircularQueue *q, char item) {
    if (q->count < SIZE) {
        q->rear = (q->rear + 1) % SIZE;
        q->data[q->rear] = item;
        q->count++;
    }
}

char dequeue(CircularQueue *q) {
    if (q->count == 0) return '\0';
    char item = q->data[q->front];
    q->front = (q->front + 1) % SIZE;
    q->count--;
    return item;
}

// Returns shifted char using the queue
char getShiftedChar(CircularQueue *q, char ch, int shift) {
    if (ch >= 'A' && ch <= 'Z') {
        int index = (ch - 'A' + shift + SIZE) % SIZE;
        return q->data[index];
    } else if (ch >= 'a' && ch <= 'z') {
        int index = (ch - 'a' + shift + SIZE) % SIZE;
        return q->data[index] + 32;
    }
    return ch;
}

