// Lista 03 - 1099 - Soma de Ímpares Consecutivos II
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        if(x > y){
            int z = x;
            x = y;
            y = z;
        }
        
        int soma = 0;
        for(x += 1 + (x % 2 != 0); x < y; x += 2){
            soma += x;
        }
        printf("%d\n", soma);
    }

    return 0;
}
