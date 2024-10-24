// Lista 05 - 1178 - Preenchimento de Vetor III
#include <stdio.h>

int main(){
    double x;
    scanf("%lf", &x);
    double n[100];
    n[0] = x;
    for(int i = 1; i < 100; i++){
        n[i] = n[i - 1] / 2.0;
    }

    for(int i = 0; i < 100; i++){
        printf("N[%d] = %.4lf\n", i, n[i]);
    }

    return 0;
}
