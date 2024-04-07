// 2454 - Flíper
#include <stdio.h>

int main(){
    int p, r;
    scanf("%d %d", &p, &r);

    if(p){
        if(r){
            printf("A\n");
        }else{
            printf("B\n");
        }
    }else{
        printf("C\n");
    }

    return 0;
}
