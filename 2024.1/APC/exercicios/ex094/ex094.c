// Lista 07 - 1181 - Linha na Matriz
#include <stdio.h>

int main(){
    int l;
    scanf("%d ", &l);
    char t;
    scanf("%c", &t);
    
    double matriz[12][12];
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            scanf("%lf", &matriz[i][j]);
        }
    }

    double soma = 0;
    for(int i = 0; i < 12; i++){
        soma += matriz[l][i];
    }

    if(t == 'M'){
        soma = soma / 12;
    }

    printf("%.1lf\n", soma);
    return 0;
}
