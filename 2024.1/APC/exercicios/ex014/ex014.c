// Lista 01 - 1018 - Cédulas
#include <stdio.h>

int main(){
    int notas[] = {100, 50, 20, 10, 5, 2, 1};

    int valor;
    scanf("%d", &valor);

    printf("%d\n", valor);

    for(int i = 0; i < 7; i++){
        int n_notas = 0;
        while(valor >= notas[i]){
            valor -= notas[i];
            n_notas++;
        }        
        printf("%d nota(s) de R$ %d,00\n", n_notas, notas[i]);
    }

    return 0;
}
