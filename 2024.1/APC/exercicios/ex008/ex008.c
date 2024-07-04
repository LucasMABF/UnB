// Lista 01 - 1012 - Área
#include <stdio.h>

int main(){
    const double pi = 3.14159;
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);

    double tri = (a * c) / 2;
    printf("TRIANGULO: %.3lf\n", tri);

    double circ = pi * c * c;
    printf("CIRCULO: %.3lf\n", circ);

    double trap = ((a + b) * c) / 2;
    printf("TRAPEZIO: %.3lf\n", trap);

    double quad = b * b;
    printf("QUADRADO: %.3lf\n", quad);

    double ret = a * b;
    printf("RETANGULO: %.3lf\n", ret);

    return 0;
}
