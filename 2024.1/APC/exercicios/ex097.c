// Lista 07 - 1185 - Acima da Diagonal Secundaria
#include <stdio.h>

int main(){
    char o;
    scanf("%c", &o);
    
    double matriz[12][12];
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            scanf("%lf", &matriz[i][j]);
        }
    }

    double soma = 0;
    int total = 0;
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            if(i + j < 11){
                soma += matriz[i][j];
                total++;
            }
        }
    }

    if(o == 'M'){
        soma = soma / total;
    }

    printf("%.1lf\n", soma);
    return 0;
}
