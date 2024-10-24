// Lista 04 - B - Lista PDF Funções
#include <stdio.h>

double calc_peso(double altura, char sexo){
    int k;
    if(sexo == 'M'){
        k = 23;
    }else{
        k = 20;
    }
    return altura * altura * k;
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        double altura;
        char sexo;
        scanf("%lf %c", &altura, &sexo);

        printf("Peso ideal: %.2lf\n", calc_peso(altura, sexo));
    }

    return 0;
}
