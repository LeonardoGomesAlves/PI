#include <stdio.h>

int mdc2 (int a, int b){
    int mdc; 

    while (a > 0){
        if (a > b) {
            a = a - b;
        }
        
        if (a < b) {
            b = b - a;  
        }

        if (a == b) {
            mdc = a;
            a = -1;
        }
    }
    printf("%d\n", mdc);
    return 0;
}

int main () {
    int a, b;

    scanf("%d %d", &a, &b);
    mdc2(a,b);
    return 0;

}