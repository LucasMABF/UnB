// Lista 03 - 1134 - Tipo de Combustível
#include <stdio.h>

int main(){
    int alcool = 0, gasolina = 0, diesel = 0;

    while(1){
        int t;
        scanf("%d", &t);
        if(t == 1){
            alcool++;
        }else if(t == 2){
            gasolina++;
        }else if(t == 3){
            diesel++;
        }else if(t == 4){
            break;
        }
    }

    printf("MUITO OBRIGADO\n");
    printf("Alcool: %d\n", alcool);
    printf("Gasolina: %d\n", gasolina);
    printf("Diesel: %d\n", diesel);

    return 0;
}
