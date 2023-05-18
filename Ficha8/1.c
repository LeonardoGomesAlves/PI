#include <stdio.h>
#include <stdlib.h>

typedef struct slist {
    int valor;
    struct slist * prox;
} * LInt;

typedef struct {
    LInt inicio, fim;
} Queue;

void initQueue (Queue *q) {
    q->inicio = NULL;
    q->fim = NULL;
}

int QisEmpty (Queue q) { // apontador é uma seta e é ->, sem ser seta (sem *) é usar .
    return q.inicio == NULL && q.fim == NULL;
}

int enqueue (Queue *q, int x) {
    LInt novo = malloc(sizeof(struct slist));
    if(!novo) return 1; //not novo, houve erro
    novo->valor = x;
    novo->prox = NULL;
    if(q->fim == NULL) {
        q->inicio = novo;
        q->fim = novo;
        return 0;
    }
    else {
        q->fim->prox = novo;
        q->fim = novo;
        return 0;
    }
}

int dequeue (Queue *q, int *x) {
    if(q->inicio == NULL) return 1;
    *x = q->inicio->valor;
    LInt inicioAntigo = q->inicio;
    q->inicio = q->inicio->prox;
    free(inicioAntigo);
    return 0;
}

int front (Queue q, int *x) {
    if(q.inicio == NULL) return 1;
    *x = q.inicio->valor;
    return 0;
}