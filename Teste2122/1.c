#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


typedef struct LInt_nodo {
    int valor;
    struct LInt_nodo *prox;
} *LInt;

typedef struct ABin_nodo {
    int valor;
    struct ABin_nodo *esq, *dir;
} *ABin;

//EXERCICIO 1

void merge(int a[], int na, int b[], int nb, int r[]) {
    int nr = na + nb;
    for (int i = 0; i < nr; i++) {
        if (nb == 0 || na > 0 && a[0] <= b[0]) {
            r[i] = a[0];
            a++;
            na--;
        }
        if (na == 0 || b[0] < a[0]){
            r[i] = b[0];
            b++;
            nb--;
        }
    }
}

void mergeSort (int r[], int N) {
    if (N <= 1) return;

    int metade = N / 2;
    int r1[metade];
    int r2[N-metade];
    for (int i = 0; i < metade; i++) r1[i] = r[i];
    for (int i = 0; i < N - metade; i++) r2[i] = r[metade+i];
    mergeSort(r1, metade);
    mergeSort(r2, N-metade);
    merge(r1, metade, r2, N-metade, r);
}


int nesimo (int a[], int N, int i) {
    mergeSort(a, N);
    return a[i-1];
}

//EXERCICIO 2

void freeL (LInt l) {
    while(l != NULL) {
        LInt temp = l->prox;
        free(l);
        l = temp;
    }
}

LInt removeMaiores (LInt l, int x) {
    LInt inicio = l;
    LInt ant = l;
    while (l != NULL) {
        if (l->valor > x) {
            freeL(l);
            break;
        }
        ant = l;
        l = l->prox;
    }
    return inicio;
}

int localiza(ABin a, int x) {
    if (a == NULL) return 0;
    if (x > a->valor) {
        localiza(a->dir, x);
    }
    if (x < a->valor) {
        localiza(a->esq, x);
    }
    if (x == a->valor) {
        return 1;
    }
}

// EXERCICIO 3
LInt caminho (ABin a, int x) {
    if (!a) return NULL;
    int existe = localiza(a, x);
    if (existe == 0) return NULL;
    else {
        LInt inicio = malloc(sizeof(struct LInt_nodo));
        LInt beggining = inicio;
        inicio->valor = a->valor;
        inicio->prox = NULL;
        while (1) {
            if (x > a->valor) {
                a = a->dir;
                LInt aux = malloc(sizeof(struct LInt_nodo));
                aux->valor = a->valor;
                aux->prox = NULL;
                inicio = inicio->prox;
                inicio = aux;

            } else if (x < a->valor) {
                a = a->esq;
                LInt aux = malloc(sizeof(struct LInt_nodo));
                aux->valor = a->valor;
                aux->prox = NULL;
                inicio = inicio->prox;
                inicio = aux;
            } else {
                return beggining;
            }
        }
    }
}

// EXERCICIO 4

void inc(char s[]){
    int size = strlen(s);
    int finish = 0;
    while (size > 0 && finish != 1) {
        if (s[size-1] != '9')
        {
            s[size-1]++;
            break;
        }
        else{
            s[size-1] = '0';
        }
        size--;
    }
}

//5

int sacos (int p[], int N, int c) {
    int total = 0;
    for (int i = 0; i < N; i++) {
        total += p[i];
    }

    int sacos = 1;
    
    int found = 0;
    for (int i = 0; found == 0; i++) {
        total -= c;
        if (total > 0 && total < c) {
            sacos++;
            found = 1;
        } 
        else if (total == 0) {
            found = 1;
        }
        else {
            sacos++;
        }
    }
    return sacos;
}

int main (){
    char add[4] = "1234";
    inc(add);
    int i = 0;
    while (i < 4) {
        printf("%c", add[i]);
        i++;
    }
}