#include <stdio.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

void merge(Aluno a[], int na,Aluno b[], int nb, Aluno aux []) {
    int nr = na + nb;
    for (int i = 0; i < nr; i++) {
        if (nb == 0 || na > 0 && a[0].numero < b[0].numero) {
            aux[i] = a[0];
            a++;
            na--;
        }
        else {
            aux[i] = b[0];
            b++;
            nb--;
        }
    }
}

void mergeSort (Aluno r[], int N) {
    if (N <= 1) return;

    int metade = N / 2;
    Aluno r1[N];
    Aluno r2[N];
    for (int i = 0; i < metade; i++) {
        r1[i] = r[i];
    }
    for (int i = metade; i < N; i++) {
        r2[i - metade] = r[i];
    }
    mergeSort(r1, metade);
    mergeSort(r2, N - metade);
    merge(r1, metade, r2, N - metade, r);
}

void ordenaPorNum (Aluno t [], int N) {
    mergeSort(t, N);
}