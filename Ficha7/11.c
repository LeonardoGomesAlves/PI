#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;

Palavras acrescentaInicio (Palavras l, char *p) {
    Palavras nova = malloc(sizeof(struct celula)); //tem que ser struct celula e não Palavras pq queremos espaço para uma celula e nao um apontador (*Palavras)
    nova->palavra = malloc(sizeof(strlen (p)) + 1); //+1 por causa do \0
    strcpy(nova->palavra, p);
    nova->ocorr = 1;
    nova->prox = l;
    return nova;
}

void listaPal (Palavras l) {
    while (l != NULL) {
        printf("%s - %d\n", l->palavra, l->ocorr);
        l = l->prox;
    }
}

Palavras novaPalavra(char *p) {
    Palavras nova = malloc(sizeof(struct celula));
    if(nova) {
        nova->palavra = malloc(strlen(p) + 1);
        if(nova->palavra) {
            strcpy(nova->palavra, p);
            nova->ocorr = 1;
            nova->prox = NULL;
        }
        else {
            free(nova);
            nova = NULL;
        }
    }
    return nova;
}

Palavras acrescenta (Palavras l, char *p) {
    if (l == NULL) {
        Palavras nova = novaPalavra(p);
        return nova;
    }
    
    if (strcmp(l->palavra, p) == 0) {
        l->ocorr++;
        return l;
    }
    if (strcmp(l->palavra, p) < 0) {
        l->prox = acrescenta(l->prox, p);
        return l;
    }
    Palavras nova = novaPalavra(p);
    nova->prox = l;
    return nova;
}

Palavras maisFreq (Palavras l) {
    Palavras mFreq = l;
    while (l) {
        if (l->ocorr > mFreq->ocorr) {
            mFreq = l;
        }
        l = l->prox;
    }
    return mFreq;
}

int main () {
    Palavras pals = NULL;
    pals = acrescentaInicio(pals, "amor");
    pals = acrescentaInicio(pals, "olá");
    listaPal(pals);
}