#include <stdio.h>

void triangulo (int n){
    int linha,coluna;
    for(linha=0; linha < n; linha++){
      for(coluna = 0; coluna <= linha; coluna++){
          putchar ('#');
      }
    putchar ('\n');
    }
    for (linha = 0; linha < n - 1; linha++){
        for (coluna = 0; coluna < n - linha - 1; coluna ++){
            putchar('#');
        }
        putchar ('\n');
    }
}