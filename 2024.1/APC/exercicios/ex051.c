// Lista 03 - 1132 - Múltiplos de 13
#include <stdio.h>

int main(){
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    if(x > y){
        int z = x;
        x = y;
        y = z;
    }

    int soma = 0;
    for(int i = x; i <= y; i++){
        soma += (i % 13 != 0) * i;
    }
    
    printf("%d\n", soma); 

    return 0;
}
