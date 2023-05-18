#include <stdio.h>
#include <math.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

int nota (Aluno a) {
    int nota_final = 0;

    float mini_testes = 0;
    for (int i = 0; i < 6; i++) {
        mini_testes = +a.miniT[i];
    }

    mini_testes = mini_testes * 10 / 6;

    nota_final = 0.8 * a.teste + 0.2 * mini_testes;

    if(nota_final < 9.5 || mini_testes < 5) {
        nota_final = 0;
    }

    return round(nota_final);
}

int procuraNum (int num, Aluno t[], int N) {
    int ind_aluno = -1;

    int i;
    for(i = 0; i < N; i++) {
        if(t[i].numero == num) {
            ind_aluno = i;
            break;
        }
    }
    return ind_aluno;
}

void ordenaPorNum (Aluno t [], int N) {
    int i;
    while (N > 1) {
        for (i = 0; i < N - 1; i++) {
            if (t[i].numero > t[i+1].numero) {
                
            }
        }
    N--;
    }
}

int main () {
    Aluno t[] = {
        {4444, "Pedro", {2,1,0,2,2,2}, 10.5},
        {2222, "Luz", {2,2,2,1,0,0}, 14.5},
        {7777, "Rita", {2,2,2,2,2,1}, 18.5},
        {3333, "Bruno", {0,0,2,2,2,1}, 8.7}
    };

    Aluno tOrd[] = {
        {2222, "Luz", {2,2,2,1,0,0}, 14.5},
        {3333, "Bruno", {0,0,2,2,2,1}, 8.7},
        {4444, "Pedro", {2,1,0,2,2,2}, 10.5},
        {7777, "Rita", {2,2,2,2,2,1}, 18.5}
    };

    int nota1 = nota(t[3]);
    printf("Nota do %s: %d\n", t[3].nome, nota1);

    int ind_aluno = procuraNum(4444, tOrd, 4);
    printf("Índice do aluno %d: %d\n", 4444, ind_aluno);

    return 0;
}