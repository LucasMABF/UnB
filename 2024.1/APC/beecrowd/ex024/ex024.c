// 1045 = Tipos de Triângulos
#include <stdio.h>
#include <math.h>

int main(){
    double a[3];
    scanf("%lf %lf %lf", &a[0], &a[1], &a[2]);

    double sorted[3];
    if(a[0] <= a[1] && a[0] <= a[2]){
        sorted[0] = a[0];
        if(a[1] <= a[2]){
            sorted[1] = a[1];
            sorted[2] = a[2];
        }else{
            sorted[1] = a[2];
            sorted[2] = a[1];
        }
    }else if(a[1] <= a[0] && a[1] <= a[2]){
        sorted[0] = a[1];
        if(a[0] <= a[2]){
            sorted[1] = a[0];
            sorted[2] = a[2];
        }else{
            sorted[1] = a[2];
            sorted[2] = a[0];
        }
    }else{
        sorted[0] = a[2];
        if(a[0] <= a[1]){
            sorted[1] = a[0];
            sorted[2] = a[1];
        }else{
            sorted[1] = a[1];
            sorted[2] = a[0];
        }
    }

    if(sorted[2] >= sorted[0] + sorted[1]){
        printf("NAO FORMA TRIANGULO\n");
    }else{
        if(pow(sorted[2], 2) == pow(sorted[0], 2) + pow(sorted[1], 2)){
            printf("TRIANGULO RETANGULO\n");
        }else if(pow(sorted[2], 2) > pow(sorted[0], 2) + pow(sorted[1], 2)){
            printf("TRIANGULO OBTUSANGULO\n");
        }else{
            printf("TRIANGULO ACUTANGULO\n");
        }

        if(sorted[0] == sorted[1] || sorted[1] == sorted[2] || sorted[2] == sorted[0]){
            if(sorted[0] == sorted[1] && sorted[1] == sorted[2]){
                printf("TRIANGULO EQUILATERO\n");
            }else{
                printf("TRIANGULO ISOSCELES\n");
            }
        }
    }

    return 0;
}
