// 1006 - Média 2
#include <stdio.h>

int main(){
        double p1;
        scanf("%lf", &p1);
        double p2;
        scanf("%lf", &p2);
        double p3;
        scanf("%lf", &p3);

        double media = ((2 * p1) + (3 * p2) + (5 * p3))  / 10;

        printf("MEDIA = %.1lf\n", media);
}