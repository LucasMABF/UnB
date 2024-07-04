// Lista 02 - 1040 - Média 3
#include <stdio.h>

int main(){
    double n1, n2, n3, n4;
    scanf("%lf %lf %lf %lf", &n1, &n2, &n3, &n4);

    double media = (2 * n1 + 3 * n2 + 4 * n3 + 1 * n4) / 10;
    printf("Media: %.1lf\n", media);

    if(media >= 7){
        printf("Aluno aprovado.\n");
    }else if(media < 5){
        printf("Aluno reprovado.\n");
    }else{
        printf("Aluno em exame.\n");

        double n5;
        scanf("%lf", &n5);
        printf("Nota do exame: %.1lf\n", n5);

        media = (media + n5) / 2;

        if(media >= 5){
            printf("Aluno aprovado.\n");
        }else{
            printf("Aluno reprovado.\n");
        }

        printf("Media final: %.1lf\n", media);

    }

    return 0;
}
