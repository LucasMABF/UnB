// Lista 03 - 1075 - Resto 2
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 2; i < 10000; i++){
        if(i % n == 2){
            printf("%d\n", i);
        }
    }

    return 0;
}
