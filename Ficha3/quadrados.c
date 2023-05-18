#include <stdio.h>

void quadrados (int q[], int N) {
    q[0] = 0;
    for (int i = 1; i < N; i++) {
        q[i] = q[i-1] + (2 * (i - 1) + 1); 
    }
}

int main() {
    int q[8];
    quadrados(q, 8);
    for (int k = 0; k < 8; k++) {
            printf("%d ", q[k]);
        }
        printf("\n");


}