// Lista 03 - 1146 - Sequências Crescentes
#include <stdio.h>

int main(){
    while(1){
        int n;
        scanf("%d", &n);
        if(n == 0) break;
        for(int i = 1; i < n; i++){
            printf("%d ", i);
        }
        printf("%d\n", n);
    }

    return 0;
}
