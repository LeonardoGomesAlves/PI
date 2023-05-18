#include <stdio.h>

int soma (int v[], int N) {
    int acc = 0;
    for (int i = 0; i < N; i++) {
        acc = v[i] + acc;
    }
    return acc;
}

int main () {
    int n, i, res;
    int v[256];

    printf("Tamanho do vetor: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("%dº elemento: ", i+1);
        scanf("%d", &v[i]);
    }
    res = soma(v,n);
    printf("Soma: %d\n", res);
    return 0;

}