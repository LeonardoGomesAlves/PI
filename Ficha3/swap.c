#include <stdio.h>

void swapM (int *x, int *y) {
    int tmp;   //Não é preciso o * pq não usamos esse valor fora desta função
    tmp = *x;
    *x = *y;
    *y = tmp;

}

int main () {
    int x = 3;
    int y = 5;
    swapM(&x, &y);
    printf("%d %d\n", x, y);
    return 0;

}