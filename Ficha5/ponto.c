#include <stdio.h>
#include <math.h>

struct ponto {
    double x;
    double y;
};

typedef struct ponto Ponto; //sinonimos para tipos;
typedef double real;

double quadrado (double a) {return a * a;}

double distancia(Ponto p1, Ponto p2) {
    return sqrt(quadrado(p1.x - p2.x) + quadrado(p1.y - p2.y));
}

int main () {
    struct ponto p1 = {4.3, 0.2};
    printf("(%f, %f)\n", p1.x, p1.y);
    p1.x = 2;
    printf("(%f, %f)\n", p1.x, p1.y);

    Ponto p2 = {-3,5};
    double dist = distancia(p1, p2);
    printf("%f\n", dist);


    return 0;
    //USAR flag -lm para compilar com funções do math.h
}