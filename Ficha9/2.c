#include <stdio.h>
#include <stdio.h>
#include "ficha9.h"


ABin newABin (int r, ABin e, ABin d) {
    ABin a = malloc(sizeof(struct nodo));
    if (a!=NULL) {
        a->valor = r; a->esq = e; a->dir = d;
    }
    return a;
}

struct nodo *procura (ABin a, int x) {
    if (!a) return NULL;
    if (a->valor == x) return a;
    if (x > a->valor) procura(a->dir, x); else procura(a->esq, x);
    return NULL;
}

int nivel (ABin a, int x) {
    if (!a) return -1;
    int nivel = 0;

    while (a != NULL) {
        if (a->valor == x) {
            return nivel;
        }
        else if (x > a->valor) {
            a = a->dir;
        }
        else {
            a = a->esq;
        }
        nivel++;
    }
    if (a == NULL) return -1;
    else return nivel;
}
int main () {
    ABin a = newABin(10, 
                newABin(7, NULL, newABin(8, NULL, NULL)), 
                newABin(12, newABin(11, NULL, NULL), newABin(13, NULL, NULL)));
    int y = nivel(a, 11);
    printf("%d\n", y);
    return 0;
}