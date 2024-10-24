// Lista 03 - 1080 - Maior e Posição
#include <stdio.h>

int main(){
    int maior, pos;
    for(int i = 0; i < 100; i++){
        int x;
        scanf("%d", &x);
        if(i == 0){
            maior = x;
            pos = 1;
        }else{
            if(x > maior){
                maior = x;
                pos = i + 1;
            }
        }
    }

    printf("%d\n", maior);
    printf("%d\n", pos);

    return 0;
}
