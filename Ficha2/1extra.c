#include <stdio.h>

int divisaoInteia (int dividendo, int divisor) {
     int i;
     for (i = 0; dividendo >= 0; i++) {
        dividendo = dividendo - divisor;
     }
    return (i-1);
}

int main(void) {
    int dividendo, divisor, quociente;
    scanf("%d/%d", &dividendo, &divisor);

    quociente = divisaoInteia(dividendo, divisor);

    printf("%d\n", quociente);
    return 0;
}