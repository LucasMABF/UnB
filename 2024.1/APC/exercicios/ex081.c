// Lista 05 - 2783 - Figurinhas da Copa
#include <stdio.h>

int main(){
    int _figurinhas, n_carimbadas, compradas;
    scanf("%d %d %d", &_figurinhas, &n_carimbadas, &compradas);

    int carimbadas[n_carimbadas];
    for(int i = 0; i < n_carimbadas; i++){
        int carimbada;
        scanf("%d", &carimbada);
        carimbadas[i] = carimbada;
    }

    int restantes = n_carimbadas;
    for(int i = 0; i < compradas; i++){
        int figurinha;
        scanf("%d", &figurinha);
        for(int j = 0; j < n_carimbadas; j++){
            if(carimbadas[j] == figurinha){
                carimbadas[j] = 0;
                restantes--;
            }
        }
    }

    printf("%d\n", restantes);

    return 0;
}
