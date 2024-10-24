// Lista 09 - 2166 - Raiz Quadrada de 2
#include <stdio.h>

double raiz(int n){
    if(n == 0) return 0;

    return 1 / (2 + raiz(n - 1));

}

int main(){
    int n;
    scanf("%d", &n);

    double resultado = 1 + raiz(n);
    printf("%.10lf\n", resultado);

    return 0;
}
