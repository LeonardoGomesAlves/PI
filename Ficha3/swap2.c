    #include <stdio.h>

    void swap (int v[], int i, int j) {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }

    int main () {
        int v[5] = {1,2,3,4,5};
        int i = 0;
        int j = 4;
        swap(v, i, j);
        for (int k = 0; k < 5; k++) {
            printf("%d ", v[k]);
        }
        printf("\n");
        return 0;
    }