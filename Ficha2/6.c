#include <stdio.h>

int fib1 (int n) {
    
    if (n < 2) {
        return n;
    }
    else {return fib1(n-1) + fib1(n-2);
    }
}

int main () {
    int n; 
    scanf("%d", &n);
    printf("%d\n", fib1(n));
    return 0;
}