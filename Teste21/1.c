#include <stdio.h>
#include <stdlib.h>

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

typedef struct nodo {
    int valor;
    struct nodo *pai, *esq, *dir;
} *ABin;

ABin newABin (int x, ABin a, ABin b) {
    ABin arvore = malloc(sizeof(struct nodo));
    if (arvore != NULL) {
        arvore->valor = x;
        arvore->esq = a;
        arvore->dir = b;
    }
    return arvore;
}

//1
int sumhtpo (int n) {
    int r = 0;
    int save = n;
    int itera = 0;
    while (n != 1) {
        r += n;
        if (n%2 == 0) {
            n = n /2; 
            itera++;
        }

        else {
            n = 1+(3*n);
            itera++;
        }
    }
    if (itera < 100) return -1;
    int array[itera];

    array[0] = n;

    for (int i = 1; i < itera; i++) {
        r += n;
        if (n%2 == 0) {
            n = n /2;
            array[i] = n;

        } else {
            n = 1+(3*n);
            array[i] = n;
        }
    }
    int real = itera - 101;
    return array[real];
}

//2
int moda (int v[], int N, int *m) {
    if (N == 0) return 0;
    if (N == 1) {
        *m = v[0];
        return 1;
    }
    int inicio = *m;
    int multimodal = 0;
    int aux = 0;
    for (int i = 0; i < N; i++) {
        int freq = 1;
        for (int j = i+1; j < N; j++) {
            if (v[i] == v[j]) {
                freq++;
            }
        }
        if (freq > aux) {
            aux = freq;
            *m = v[i];
        } 
    }

    for (int i = 0; i < N; i++) {
        int freq = 1;
        for (int j = i+1; j < N; j++) {
            if (v[i] == v[j]) {
                freq++;
            }
        }
        if (freq == aux) {
            multimodal++;
        } 
    }


    if (multimodal == 1) return aux;
    else {
        *m = inicio;
        return 0;}
}

//3
int procura (LInt *l, int x) {
    if (*l == NULL) return 0;
    LInt cursor = *l;
    LInt inicio = cursor;
    LInt ant = cursor;
    while (cursor != NULL) {
        if (cursor->valor == x) {
            LInt aux = cursor->prox;;
            ant->prox = aux;
            cursor->prox = inicio;
            *l = cursor;
            return 1;
        }
        ant = cursor;
        cursor = cursor->prox;
    }
    return 0;
}

//4
int freeAB (ABin a) {
    if (a == NULL) return 0;
    ABin esq = a->esq;
    ABin dir = a->dir;
    free(a);
    return (1 + freeAB(esq) + freeAB(dir));
}


//5

void reverseL (int l[], int N) {
    for (int i = 0; i < N / 2; i++) {
        int temp = l[i];
        l[i] = l[N-1-i];
        l[N-1-i] = temp;
    }
}

void caminho(ABin a) {
    if (a == NULL) return;
    int i = 0;
    while (a != NULL) {
        a = a->pai;
        i++;
    }
    int tamanho = i-1;
    int array[tamanho]; // 0-esquerda ; 1-direita
    for (int k = 0; k < tamanho; k++) {
        ABin temp = a;
        a = a->pai;
        if (temp == a->dir) {
            array[k] = 1;
        }
        if (temp == a->esq) {
            array[k] = 0;
        }
    }
    reverseL(array, tamanho);
    for (int k = 0; k < tamanho; k++) {
        if (array[k] == 1) {
            printf("dir\n");
        } else {
            printf("esq\n");
        }
    }
}

int main () {
    ABin tree = newABin(3, newABin(4, NULL, newABin(5, NULL, NULL)), newABin(1, NULL, NULL));
    int x = freeAB(tree);
    printf("%d", x);
    return 0;
}