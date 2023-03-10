#include <stdio.h>

int fib2 (int n) {
    int i,fi1, fi2,soma;
    fi1 = 1;
    fi2 = 1;

    for(i = 2; i <= n; i++) {
        soma = fi1 + fi2;
        fi1 = fi2;
        fi2 = soma; 
    }
    return soma;

}

int main () {
    int n;
    scanf("%d", &n);
    printf("%d\n", fib2(n));
    return 0;
}