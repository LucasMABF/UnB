// Lista 03 - 1101 - Sequência de Números e Soma
#include <stdio.h>

int main(){
    while(1){
        int m, n;
        scanf("%d %d", &m, &n);
        if(m <= 0 || n <= 0){
            break;
        }

        if(n < m){
            int p = n;
            n = m;
            m = p;
        }

        int soma = 0;
        for(int j = m; j <= n; j++){
            printf("%d ", j);
            soma += j;
        }
        printf("Sum=%d\n", soma);
    }


    return 0;
}
