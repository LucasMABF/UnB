// Lista 01 - 1009 - Salário com Bônus
#include <stdio.h>

int main(){
        char nome[50];
        scanf("%s", nome);

        double salario;
        scanf("%lf", &salario);

        double com;
        scanf("%lf", &com);

        double tot = (15.0/100.0 * com) + salario;

        printf("TOTAL = R$ %.2lf\n", tot);
        return 0;
}
