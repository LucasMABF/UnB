// Lista 01 - 1015 - Distância Entre Dois Pontos
#include <stdio.h>
#include <math.h>

int main(){
    double p1[2];
    scanf("%lf %lf", &p1[0], &p1[1]);

    double p2[2];
    scanf("%lf %lf", &p2[0], &p2[1]);

    double dist = sqrt(pow((p2[0] - p1[0]), 2) + pow((p2[1] - p1[1]), 2));

    printf("%.4lf\n", dist);

    return 0;
}