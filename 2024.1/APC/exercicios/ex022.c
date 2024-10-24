// Lista 02 - 1043 - Triângulo
#include <stdio.h>

int main(){
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);

    if(a < b + c && b < a + c && c < a + b){
        double per = a + b + c;
        printf("Perimetro = %.1lf\n", per);
    }else{
        double area = (a + b) * c / 2;
        printf("Area = %.1lf\n", area);
    }


    return 0;
}
