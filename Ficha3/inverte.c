#include <stdio.h>

void swapM (int *x, int *y) {
    int tmp;   //Não é preciso o * pq não usamos esse valor fora desta função
    tmp = *x;
    *x = *y;
    *y = tmp;

}

void inverteArray(int v[], int N) {
    int metade = N / 2; 
    for (int i = 0; i < metade; i++) {
        swapM(v+i, v+N-i-1);
    }
}

int main () {
    int v[5] = {1,2,3,4,5};
    inverteArray(v, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;

}