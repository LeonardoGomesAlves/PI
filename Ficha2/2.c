#include <stdio.h>

float multInt2 (int n, float m) {
    float acc;
    acc = 0;

    while(n > 0){

        if ((n % 2) != 0) {
            acc = acc + m;
        }


        m = m * 2;
        n = n / 2;

    }
    return acc;

}   

float main () {

    int n;
    float m;

    scanf("%d %f", &n, &m);

    float result = multInt2(n,m);
    printf("%f\n", result);

    return 0;

}




