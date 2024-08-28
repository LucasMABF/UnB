// Lista 09 - 1151 - Fibonacci Fácil
#include <stdio.h>
#include <stdlib.h>

int calc_fib(int *fib, int x, int len){
    if(x > len){
        for(int i = len; i < x + 1; i++){
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        return x + 1;
    }
    return x;

}

int main(){
    int n;
    scanf("%d", &n);

    int *fib = malloc(n * sizeof(int));
    int len = 2;
    fib[0] = 0;
    fib[1] = 1;
    calc_fib(fib, n, len);

    for(int i = 0; i < n; i++){
        printf("%d", fib[i]);
        if(i != n - 1){
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
