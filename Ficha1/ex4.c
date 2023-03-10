#include <stdio.h>

int quadrado(int x) {
  return x * x;
}

int dentro_do_circulo(int raio, int x, int y) {
  return quadrado(x - raio) + quadrado(y - raio) <= quadrado(raio);
}

int circulo(int raio) {
  int cardinais = 0;
  int x, y;
    for (x = 0; x < 2 * raio + 1; x++) {
        for (y = 0; y < 2 * raio + 1; y++) {
            if (dentro_do_circulo(raio, x, y)) {
                putchar('#');
                cardinais++;
            }
            else {
                putchar (' ');
            }
        }
        putchar ('\n');
    }


  return cardinais;
}

int main(void) {
  int raio, cardinais;
  scanf("%d", &raio);
  cardinais = circulo(raio);
  printf("Foram impressos %d cardinais.\n", cardinais);
  return 0;
}