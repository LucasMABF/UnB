// Lista 09 - 1441 - Sequências de Granizo
#include <stdio.h>

int sequencia(int n){
    if(n == 1) return 1;

    int n_1;
    if(n % 2 == 0){
        n_1 = n / 2;
    }else{
        n_1 = 3 * n + 1;
    }
    
    int maior = sequencia(n_1);
    if(maior < n){
        return n;
    }else{
        return maior;
    }
}

int main(){
    while(1){
        int n;
        scanf("%d", &n);
        if(n == 0) break;
        
        printf("%d\n", sequencia(n));

    }

    return 0;
}
