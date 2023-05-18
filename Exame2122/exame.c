#include <stdio.h>
#include <stdlib.h>
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
int pesquisa (int a[], int N, int x) {
    int found = 0;
    if (x > a[N-1]) return -1;
    if (x < a[0]) return -1;
    for (int i = 0; i < N; i++) {
        if (a[i] == x) {
            return i;
        }
    }
    return -1;
}

//EXERCICIO 2
void roda (LInt *l) {
    if (*l == NULL) return;
    LInt cursor = *l;
    LInt inicio = cursor;
    LInt segundo = cursor;
    LInt ant = cursor;
    while (cursor != NULL) {
        if (cursor->prox == NULL) {
            ant->prox = NULL;
            inicio = cursor;
            inicio->prox = segundo;
            break;
        }
        ant = cursor;
        cursor = cursor->prox;
    }
}


//EXERCICIO 3

int contaNos (ABin a) {
    if (a == NULL) {return 0;}
    else {
    return (1+contaNos(a->esq) + 1+contaNos(a->dir));
    }
}
int apaga (ABin a, int n) { 
    if (a == NULL) return 0;
    int n_nos = contaNos(a);
    if (n >= n_nos) {
        apaga(a->esq, n_nos);
        apaga(a->dir, n_nos);
        free(a);
        return n_nos;
    }
}



//EXERCICIO 4

void reverseL (char s[]) {
    int tamanho = strlen(s);
    for (int i = 0; i < tamanho / 2; i++) {
        char temp = s[i];
        s[i] = s[tamanho-i-1];
        s[tamanho-i-1] = temp;
    }
}

void checksum (char s[]) {
    int tamanho = strlen(s);
    reverseL(s);
    int sum = 0;
    for (int i = 0; i < tamanho;i++) {
        int valor = s[i] - '0';
        if (i % 2 == 0) {
            if (valor * 2 > 9) {
                valor = ((valor * 2) % 10) + 1;
            } else {
                valor = 2 * valor;
            }
        }
        sum += valor;
    }
    int indice = 0;

    while (sum % 10 != 0) {
        indice++;
        sum++;
    }
    reverseL(s);
    s[tamanho] = indice + '0';
    s[tamanho+1] = '\0';
}

int escolhe (int N, int valor[], int peso[], int C, int quant[]) {
    for (int i = 0; i < N; i++) {
        quant[i] = 0;
    }
    int found = 0;
    int sum = 0;
    int aux = 0;

    for (int j = 0; j < N; j++) {
        for (int i = 0; aux <= C;i++) {
            if (i == N) i = 0; //voltar ao inicio
            aux = aux + peso[i];
            if (aux > C) {
                aux = aux-peso[i];
                break;
            } 
            if (aux == C) {
                quant[i]++;
                sum = sum + valor[i];
                break;
            } 
            if (aux < C) {
                quant[i]++;
                sum = sum + valor[i];
            }
        }
    }
    
    return sum;
}
int main () {
    int valor[3] = {20,150,30};
    int pesos[3] = {2,10,3};
    int quant[3];
    int total = escolhe(3, valor, pesos, 14, quant);
    for (int i = 0; i < 3; i++) {
        printf("%d ", quant[i]);
    }
    printf("%d", total);
    return 0;
}