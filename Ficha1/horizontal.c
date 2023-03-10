#include <stdio.h>


void triangulo2 (int n){
    int linha,coluna;
    for(linha = 0; linha < n; linha++){
        for(coluna = 0; coluna < n - linha - 1; coluna++){
            putchar(' ');
        }
        for(coluna = 0; coluna < 2 * linha + 1; coluna++){
            putchar('#');
        }
        putchar('\n');
    }
}

void triangulo (int n){
    int linha;
    for(linha = 0; linha < n; linha++){
        imprime_n(' ', n - linha - 1);
        imprime_n('#', 2 * linha + 1);
        putchar('\n');
    }
}