// Lista 07 - 1478 - Matriz Quadrada II
#include <stdio.h>
#include <stdlib.h>

int main(){
    while(1){
        int n;
        scanf("%d", &n);

        if(n == 0) break;


        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j != 0){
                    printf(" ");
                }
                printf("%3d", abs(i - j) + 1);
            }
            printf("\n");
        }

        printf("\n");
    }

    return 0;
}
