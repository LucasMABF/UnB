// 1010 Cálculo Simples
#include <stdio.h>

int main(){
        int a;
        double b;
        double c;
        scanf("%d %lf %lf", &a, &b, &c);
        int a1;
        double b1;
        double c1;
        scanf("%d %lf %lf", &a1, &b1, &c1);

        double val = (b * c) + (b1 * c1);

        printf("VALOR A PAGAR: R$ %.2lf\n", val);
        return 0;
}
