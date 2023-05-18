#include <stdio.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

int procuraNum (int num, Aluno t[], int N) {
    int finish = 0;
    int indice = -1;
    for (int i = 0; i <= t[i].numero && indice == -1; i++) {
        if (num == t[i].numero) {
            indice = i;
        }
    }
    return indice;
}
