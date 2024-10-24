// Lista 04 - A - Lista PDF Funções
#include <stdio.h>

double coef(double x0, double y0, double x1, double y1){
    return (y1 - y0) / (x1 - x0);
}

int main(){
    double x0, y0, x1, y1;
    scanf("%lf %lf %lf %lf", &x0, &y0, &x1, &y1);

    printf("%.2lf\n", coef(x0, y0, x1, y1));


    return 0;
}
