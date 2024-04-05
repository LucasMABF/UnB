// 1014 - Consumo
#include <stdio.h>

int main(){
    int km;
    scanf("%d", &km);

    double litros;
    scanf("%lf", &litros);

    double consumo = km / litros;

    printf("%.3lf km/l\n", consumo);

    return 0;
}