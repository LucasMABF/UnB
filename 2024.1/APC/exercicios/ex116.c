// Lista 09 - 2232 - Triângulo de Pascal
#include <stdio.h>
#include <math.h>

int soma_pow2(int n){
    if(n == 1) return 1;

    return pow(2, n - 1) + soma_pow2(n - 1);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int linhas;
        scanf("%d", &linhas);

        printf("%d\n", soma_pow2(linhas));
    }

    return 0;
}
