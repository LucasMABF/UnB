// Lista 09 - 1153 - Fatorial Simples
#include <stdio.h>

int fatorial(int n){
    if(n == 1 || n == 0){
        return 1;
    }
    return n * fatorial(n - 1);
}

int main(){
    int n;
    scanf("%d", &n);
    
    printf("%d\n", fatorial(n));

    return 0;
}
