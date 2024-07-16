// Lista 05 - 1176 - Fibonacci em Vetor
#include <stdio.h>
#include <stdlib.h>

int calc_fib(unsigned long long int *fib, int x, int len){
    for(int i = len; i < x + 1; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return x + 1;
}

int main(){
    unsigned long long int *fib = malloc(2 * sizeof(unsigned long long int));
    int len = 2;
    fib[0] = 0;
    fib[1] = 1;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        if(x >= len){
            fib = realloc(fib, (sizeof(unsigned long long int) * (x + 1)));
            len = calc_fib(fib, x, len);
        }
        printf("Fib(%d) = %llu\n", x, fib[x]);
    }

    return 0;
}
