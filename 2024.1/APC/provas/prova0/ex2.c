// 2774 - Precisão do Sensor
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int h, m;
    while(scanf("%d %d", &h, &m) != EOF){
        int n = (h * 60) / m; // quantidade valores

        long double valores[n];

        long double soma = 0;
        for(int i = 0; i < n; i++){
            scanf("%Lf", &valores[i]);
            soma += valores[i];
        }
        long double media = soma / n;
        long double somatorio = 0;
        for(int j = 0; j < n; j++){
            somatorio += powl(valores[j] - media, 2);
        }
        
        long double resultado = sqrtl(somatorio / ((long double)(n - 1)));

        printf("%.5Lf\n", resultado);
    }
    
    return 0;
}
