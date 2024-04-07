// 1038 - Lanche
#include <stdio.h>

int main(){
    double precos[5] = {4.0, 4.5, 5.0, 2.0, 1.5};

    int cod, quant;
    scanf("%d %d", &cod, &quant);

    double tot = precos[cod - 1] * quant;
    printf("Total: R$ %.2lf\n", tot);

    return 0;
}
