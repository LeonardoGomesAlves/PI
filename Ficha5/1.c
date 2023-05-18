#include <stdio.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

double media(Aluno p1) {
    int acc = 0;
    for (int i = 0; p1.miniT[i]; i++) {
        acc += p1.miniT[i];
    }
    return (acc / 6);
}

int nota (Aluno a) {
    int nota_final;
    int mediaT = media(a);

    nota_final = 0.8 * a.teste + 0.2 * mediaT;

    if (nota_final >= 9.5) {
        return nota_final;
    } else {
        return 0;
    }
}
int main () {
    Aluno a = {4444, "André", {2,1,0,2,2,2}, 10.5};
    int j = nota(a);
    printf("%d", j);
    return 0;
}