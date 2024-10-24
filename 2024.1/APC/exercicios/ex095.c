// Lista 07 - 1182 - Coluna na Matriz
#include <stdio.h>

int main(){
    int c;
    scanf("%d ", &c);
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
        soma += matriz[i][c];
    }

    if(t == 'M'){
        soma = soma / 12;
    }

    printf("%.1lf\n", soma);
    return 0;
}
