// Lista 01 - 1002 - Área do Círculo
#include <stdio.h>

int main(){
        const double pi = 3.14159;

        double raio;
        scanf("%lf", &raio);

        double area = pi * raio * raio;

        printf("A=%.4f\n", area);
}