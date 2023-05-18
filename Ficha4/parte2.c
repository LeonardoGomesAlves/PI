#include <stdio.h>

void merge (int a[], int na, int b[], int nb, int r[]) {
    int nr = na + nb;
    for (int i = 0; i < nr; i++){
        if (nb == 0 || a[0] < b[0]) {
            r[i] = a[0];
            a++; //aumenta o apontador do a, sendo agora a posição 0 = a[1]
            na--;
        }
        else {
            r[i] = b[0];
            b++;
            nb--;
        }
    }
}

void mergeSort(int r[], int N) {
    if (N <= 1) return; //sai da função
    int metade= N / 2;
    int r1[N];
    int r2[N];
    for (int i = 0; i < metade; i++)
        r1[i]= r[i];
    for (int i = metade; i < N; i++)
        r2[i - metade] = r[i];
    mergeSort(r1, metade);
    mergeSort(r2, N - metade); //caso for impar terá um a mais
    merge(r1, metade, r2, N - metade, r);
}


int main () {
    int a[] = {2,4,5};
    int b[] = {1,3};
    int r[5];

    merge(a, 3, b, 2, r);
    for (int i = 0; i < 5; i++)
        printf("%d ", r[i]);
    printf("\n");

    int r2[] = {3,1,4,2,5};
    mergeSort{r2, 5};
    

}