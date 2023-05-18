#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;

void libertaLista (Palavras l) {
    Palavras aux;
    while (l != NULL){  
        aux = l->prox;
        free(l->palavra); //usa-se seta pq o Palavras é um apontador; == (*l).palavras
        free (l);
        l = aux;
    }
}

int quantasP (Palavras l) {
    int counter = 0;
    while (l != NULL) {
        counter++;
        l = l->prox;
    }
    return counter;
}

char * ultima (Palavras l) {
    while (l != NULL) {
        if (l->prox == NULL) {
            return (l->palavra);
        }
        l = l->prox;
    }
    return NULL;
}

Palavras acrescentaInicio (Palavras l, char *p) {
    Palavras novo = malloc(sizeof(struct celula)); //armazenar UMA SÓ struct
    novo->ocorr = 1;
    novo->prox = l;
    char *aux = malloc(sizeof(char) * strlen(p) + 1); //fica com endereço random se inicializo sem nada, por isso faço um malloc para guardar a array de chars e +1 por causa do '\0';
    strcpy(aux,p);
    novo->palavra = aux;
    return novo;

}

Palavras acrescentaFim (Palavras l, char *p) {
    Palavras aux = malloc(sizeof(Palavras));
    char *paux = malloc(sizeof(char) * strlen (p) + 1);
    strcpy(paux,p);
    if (l == NULL) {
        l->palavra = paux;
        l->ocorr = 1;
        l->prox = NULL;
    }
    else {
        while (l != NULL) {
            if (l->prox == NULL) {
                break;
            }
        }
        l->prox = (p,1,NULL);
    }
    return l;
}

Palavras acrescenta (Palavras l, char *p) {
    Palavras aux = l;
    while (l->prox != NULL) {
        if ((strcmp(l->palavra,p)) == 0) {
            l->ocorr++;
            return l;
        }
        l = l->prox;
    }
    acrescentaInicio(aux, p);
    return aux;
}

struct celula * maisFreq (Palavras l) {

}


int main () {
    Palavras z = {"nome", 4,};
    Palavras y = {"oas", 2,&z};
    Palavras k = {"kkk", 1, &y};

    acrescentaFim(k, "ola");
    
}