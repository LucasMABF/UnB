// 1064 - Positivos e Média
#include <stdio.h>

int main(){
    int pos = 0;
    double soma_pos = 0;
    for(int i = 0; i < 6; i++){
        double x;
        scanf("%lf", &x);

        if(x > 0){
            pos++;
            soma_pos += x;
        }
    }

    printf("%d valores positivos\n", pos);
    double media = soma_pos / pos;
    printf("%.1lf\n", media);

    return 0;
}
