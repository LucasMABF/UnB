// 2235 - Anando no Tempo
#include <stdio.h>

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if(a == b || a == c || b == c || a + b == c || c + b == a || c + a == b){
        printf("S\n");
    }else{
        printf("N\n");
    }

    return 0;
}
