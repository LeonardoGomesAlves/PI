#include <stdio.h>

#define Max 1000

typedef struct staticQueue {
    int front;
    int length;
    int values [Max];
} QUEUE, *SQueue;

void SinitQueue (SQueue q) {
    q->length = 0;
}

int SisEmptyQ (SQueue q) {
    if (q->length == 0) {
        return 0;
    }
    else {return 1;}
}

int Senqueue (SQueue q, int x) {
    if (q->front + q->length >= Max) {return 1;}
    else {
        q->values[q->length + q->front] = x;
        q->length++;
        return 0;
    }
}

int Sdequeue (SQueue q, int *x) {
    if (q->length == 0) {return 1;}
    else {
        *x = q->values[(q->front)++];
        q->length--;
    }
}


