// Lista 03 - 1164 - Número Perfeito
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    for(; n > 0; n--){
        int x;
        scanf("%d", &x);
        int soma = 0;
        for(int i = 1; i <= (x/2); i++){
            if(x % i == 0){
                soma += i;
            }
        }

        if(soma == x){
            printf("%d eh perfeito\n", x);
        }else{
            printf("%d nao eh perfeito\n", x);
        }
    }    

    return 0;
}
