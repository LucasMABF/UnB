// 2780 - Basquete de Robôs
#include <stdio.h>

int main(){
    int dist;
    scanf("%d", &dist);

    if(dist <= 800){
        printf("1\n");
    }else if(dist <= 1400){
        printf("2\n");
    }else{
        printf("3\n");
    }

    return 0;
}
