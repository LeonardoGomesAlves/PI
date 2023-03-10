#include <stdio.h>

void linhaimpar(int n){
    int i; i = 0;
    while (i<n){
        if (i%2 == 0) putchar ('#');
        else putchar('_');
        i++;
    }
}

void linhapar(int n){
    int i; i = 0;
    while (i<n){
        if (i%2 == 0) putchar ('_');
        else putchar('#');
        i++;
    }
}

int main (int n){
    int i; i = 0;
    if ((scanf ("%d", &n)) != 1) {return 1;}
    while (i<n){
        if (i%2 == 0) linhaimpar(n);
        else linhapar(n);
        i++;
        putchar('\n');
    }
  return 0;
}