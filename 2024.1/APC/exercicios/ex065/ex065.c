// Lista 04 - 6 - Lista PDF Funções 2
#include <stdio.h>

void leitura(int *codigo, double *n1, double *n2, double *n3){
    scanf("%d %lf %lf %lf", codigo, n1, n2, n3);
}

double media(double n1, double n2, double n3){
    return (n1 * 3 + n2 * 3 + n3 * 4) / 10.0;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int codigo;
        double n1, n2, n3;
        leitura(&codigo, &n1, &n2, &n3);
        double m = media(n1, n2, n3);
        printf("%.2lf\n", m);
    }

    return 0;
}
