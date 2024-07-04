// Lista 01 - 1011  - Esfera
#include <stdio.h>
#include <math.h>

int main(){
        const double pi = 3.14159;
        double raio;
        scanf("%lf", &raio);
        double vol = 4.0/3 * pi * pow(raio, 3);

        printf("VOLUME = %.3f\n", vol);
        return 0;
}
