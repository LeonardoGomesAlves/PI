#include <stdio.h>
#include <stdlib.h>

typedef struct dlist {
    int valor;
    struct dlist *ant, *prox;
} *DList;
typedef struct {
    DList back, front;
} Deque;

void initDeque (Deque *q) {
    q->back = NULL;
    q->front = NULL;
} 

int DisEmpty (Deque q) {
    return q.back == NULL && q.front == NULL;
}

int pushBack (Deque *q, int x) {
    DList nova = malloc(sizeof(struct dlist));
    if (!nova) return 1;
    if (q->back == NULL) {
        nova->valor = x;
        nova->prox = q;
        nova->ant = NULL;
        q->back = nova;
        return 0;
    }
    else {
        while (q->back != NULL) {
            q = q->back;
        }
        nova->valor = x;
        nova->prox = q;
        nova->ant = NULL;
        q->back = nova;
        return 0;
    }
}

int pushFront (Deque *q, int x) {
    DList nova = malloc(sizeof(struct dlist));
    if (!nova) return 1;
    if (q->front == NULL) {
        nova->valor = x;
        nova->prox = NULL;
        nova->ant = q;
        q->front = nova;
        return 0;
    } 
    else {
        while (q->front != NULL) {
            q = q->front;
        }
        nova->valor = x;
        nova->prox = NULL;
        nova->ant = q;
        q->front = nova;
        return 0;
    }
}