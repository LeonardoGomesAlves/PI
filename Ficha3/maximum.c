#include <stdio.h>

int maximum (int v[], int N, int *m) {
    if (N == 0) return 1;
    int m_temp = v[0];
    for (int i = 0; i < N; i++) {
        if (v[i] > m_temp)
            m_temp = v[i];
    }
    *m = m_temp;
    return 0;
}

int main () {
    int v[6] = {2,3,4,5,6,7};
    int m = 28374923;
    if(maximum(v, 6, &m) == 0) {

    printf("Máximo: %d\n", m);
    }
    else {
        printf("Erro- vetor vazio.\n");
    }
    return 0;
}