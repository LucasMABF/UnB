// Lista 03 - 1065 - Pares entre Cinco Números
#include <stdio.h>

int main(){
    int pares = 0;

    for(int i = 0; i < 5; i++){
        int x;
        scanf("%d", &x);

        if(x % 2 == 0) pares++;
    }

    printf("%d valores pares\n", pares);

    return 0;
}
