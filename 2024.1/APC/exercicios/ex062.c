// Lista 04 - D - Lista PDF Funções
#include <stdio.h>

double x, y;

void LePonto(){
    scanf("%lf %lf", &x, &y);
}

int main(){
    LePonto();
    double x0 = x;
    double y0 = y;

    LePonto();
    double x1 = x;
    double y1 = y;

    if(x0 != x1){
        printf("%.2lf\n", (y1 - y0) / (x1 - x0));
    }else{
        printf("Nao eh possivel determinar o coeficiente angular\n");
    }
    
    return 0;
}
