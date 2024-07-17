// Lista 05 - 1178 - Preenchimento de Vetor IV
#include <stdio.h>

int main(){
    int pares[5];
    int index_pares = 0;
    int impares[5];
    int index_impares = 0;
    for(int i = 0; i < 15; i++){
        int x;
        scanf("%d", &x);
        if(x % 2 == 0){
            if(index_pares == 5){
                for(int j = 0; j < 5; j++){
                    printf("par[%d] = %d\n", j, pares[j]);
                }
                index_pares = 0;
            }
            pares[index_pares] = x;
            index_pares++;
        }else{
            if(index_impares == 5){
                for(int j = 0; j < 5; j++){
                    printf("impar[%d] = %d\n", j, impares[j]);
                }
                index_impares = 0;
            }
            impares[index_impares] = x;
            index_impares++;
        }
    }

    for(int i = 0; i < index_impares; i++){
        printf("impar[%d] = %d\n", i, impares[i]);
    }

    for(int i = 0; i < index_pares; i++){
        printf("par[%d] = %d\n", i, pares[i]);
    }

    return 0;
}
