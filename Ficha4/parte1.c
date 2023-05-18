#include <stdio.h>



int ordenado (int v[], int N) {
    for(int i = 0; i < N-1; i++) {
        if(!v[i] < v[i+1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int v[4] = {1,2,3,4};
    int value = ordenado(v,4);

    if (value == 0) {
        printf("Não está ordenado.");
    }
    else {
        printf("Está ordenado.");
    }
}