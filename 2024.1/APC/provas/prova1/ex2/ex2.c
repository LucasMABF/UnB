// 2369 - Conta de Água
#include <stdio.h>

int main(){
    int c;
    scanf("%d", &c);

    int resto = c;
    int p = 7;
    for(;resto > 100; resto--){
        p += 5;
    }
    for(; resto > 30; resto--){
        p += 2;
    }
    for(; resto > 10; resto--){
        p += 1;
    }

    printf("%d\n", p);

    return 0;
}
