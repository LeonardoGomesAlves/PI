#include <stdio.h>

int mdc1 (int a, int b){
    // int menor = a < b ? a : b; se a for menor que b entao a, senao b
    int i,menor,maior;
    if (a<b) {menor = a;}
    else {menor = b;}
    int mdc = 1;

    for (i = 2; i <= menor; i++){
        if (a % i == 0 && b % i == 0){
            mdc = i;
        } 
    }
    printf ("%d\n", mdc);
    return 0;
}

int main () {
    int a, b;

    scanf("%d %d", &a, &b);
    mdc1(a,b);
    return 0;
}