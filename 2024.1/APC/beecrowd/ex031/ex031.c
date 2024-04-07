// 2417 - Campeonato
#include <stdio.h>

int main(){
    int c[3];
    int f[3];
    scanf("%d %d %d %d %d %d", &c[0], &c[1], &c[2], &f[0], &f[1], &f[2]);

    if(3 * c[0] + c[1] > 3 * f[0] + f[1]){
        printf("C\n");
    }else if(3 * c[0] + c[1] < 3 * f[0] + f[1]){
        printf("F\n");
    }else{
        if(c[2] > f[2]){
            printf("C\n");
        }else if(c[2] < f[2]){
            printf("F\n");
        }else{
            printf("=\n");
        }
    }

    return 0;
}
