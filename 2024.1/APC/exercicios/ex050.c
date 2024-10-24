// Lista 03 - 1117 - Validação de Nota
#include <stdio.h>

int main(){
    double p1, p2;

    while(1){
        scanf("%lf", &p1);
        if(p1 >= 0 && p1 <= 10){
            break;
        }
        
        printf("nota invalida\n");
    }

    while(1){
        scanf("%lf", &p2);
        if(p2 >= 0 && p2 <= 10){
            break;
        }

        printf("nota invalida\n");
    }
    
    double media = (p1 + p2) / 2.0;
    printf("media = %.2lf\n", media);

    return 0;
}
