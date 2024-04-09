// 1066 - Pares, Ímpares, Positivos e Negativos
#include <stdio.h>

int main(){
    int pares = 0;
    int pos = 0;
    int neg = 0;
    
    for(int i = 0; i < 5; i++){
        int x;
        scanf("%d", &x);
        pos += x > 0;
        
        neg += x < 0;

        pares += (x % 2 == 0);

    }

    printf("%d valor(es) par(es)\n", pares);
    printf("%d valor(es) impar(es)\n", 5 - pares);
    printf("%d valor(es) positivo(s)\n", pos);
    printf("%d valor(es) negativo(s)\n", neg);

    return 0;
}
