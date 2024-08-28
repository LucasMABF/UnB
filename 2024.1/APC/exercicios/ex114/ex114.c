// Lista 09 - 2161 - Raiz Quadrada de 10
#include <stdio.h>

double raiz(int n){
    if(n == 0) return 0;

    return 1 / (6 + raiz(n - 1));

}

int main(){
    int n;
    scanf("%d", &n);

    double resultado = 3 + raiz(n);
    printf("%.10lf\n", resultado);

    return 0;
}
