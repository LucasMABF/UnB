// 2157 - Sequência Espelho
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int c;
    scanf("%d", &c);

    for(int i = 0; i < c; i++){
        int b, e;
        scanf("%d %d", &b, &e);

        for(int j = b; j <= e; j++){
            printf("%d", j);
        }

        for(int j = e; j >= b; j--){
            int size = log10(j) + 2;
            char s[size];
            snprintf(s, size, "%d", j);
            for(int k = size - 2; k >= 0; k--){
                printf("%c", s[k]);
            }
        }

        printf("\n");
    }

    return 0;
}
