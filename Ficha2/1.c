#include <stdio.h>

float multInt1 (int n, float m){
    int i, res = 0;;

    for(i = 0; i < n; i++) {
        res += m;
    }
    return res;
}

float main () {
    int n;
    float m;

    scanf("%d %f", &n, &m);
    float res = multInt1(n,m);
    printf ("%d * %f = %f\n", n, m, res);
    return 0;
}
