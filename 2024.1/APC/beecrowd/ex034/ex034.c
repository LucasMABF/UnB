// 1060 - Números Positivos
#include <stdio.h>

int main(){
    int pos = 0;
    for(int i = 0; i < 6; i++){
        double x;
        scanf("%lf", &x);
        if(x > 0) pos++;
    }

    printf("%d valores positivos\n", pos);

    return 0;
}
