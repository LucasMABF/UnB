// Lista 01 - 1017 - Gasto de Combustivel
#include <stdio.h>

int main(){
    int tempo;
    scanf("%d", &tempo);
    int vel;
    scanf("%d", &vel);

    int km = tempo * vel;
    double litros = km / 12.0;

    printf("%.3lf\n", litros);

    return 0;
}