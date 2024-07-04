// Lista 04 - C - Lista PDF Funções
#include <stdio.h>
#include <math.h>

int calc_pot(int x, int y){
    if(y < 0){
        return -1;
    }
    int result = 1;
    for(int i = 0; i < y; i++){
        result *= x;
    }
    return result;
}

int main(){

    int x, y;
    scanf("%d %d", &x, &y);
    int resultado = calc_pot(x, y);
    if(resultado < 0){
        printf("Ainda nao lidamos com expoentes negativos\n");
    }else{
        printf("%d\n", resultado);
    }

    return 0;
}
