#include <stdio.h>
#include "ficha9.h"

ABin newABin (int r, ABin e, ABin d) {
    ABin a = malloc(sizeof(struct nodo));
    if (a!=NULL) {
        a->valor = r; a->esq = e; a->dir = d;
    }
    return a;
}

int altura (ABin a) {
    if(!a) return 0;
    int al = altura(a->esq);
    int ar = altura(a->dir);

    if (al > ar) return al + 1;
    else return ar + 1;
}

int nFolhas (ABin a) {
    if (a->esq == NULL || a->dir == NULL) return 1;
    
    return nFolhas(a->esq)+nFolhas(a->dir);
}

ABin maisEsquerda (ABin a) {
    if (!a) return NULL;
    if(!a->esq) return a;
    return maisEsquerda(a->esq);   

}

void printABin (ABin a, int indent) {
    if (a != NULL) {
        printABin(a->dir, indent + 1);
        for (int i = 0; i < indent; i++) {
            printf("      ");
        }
        printf("%d\n", a->valor);
        printABin(a->esq, indent + 1);
    }
}

void imprimeNivel (ABin a, int l) {
    if (a) {
        if (l == 0) printf("%d\n", a->valor);
    } else {
        imprimeNivel(a->esq, l-1);
        imprimeNivel(a->dir, l-1);
    }
}

int procuraE (ABin a, int x) {
    if (!a) return 0;
    if (a->valor == x) return 1;
    return procuraE(a->esq, x) || procuraE(a->dir, x);
}

#define MAX(x,y) (x > y ? x : y) //se x > y entao x, caso contrário y

int main () {
    ABin a = newABin(1, 
                newABin(2, 
                    NULL, 
                    newABin(3, 
                        NULL, 
                        NULL)), 
                    newABin(4, 
                        newABin(2, NULL, NULL), 
                        newABin(4, NULL, NULL)));
    maisEsquerda(a);
    printABin(a, 1);
    return 0;
}