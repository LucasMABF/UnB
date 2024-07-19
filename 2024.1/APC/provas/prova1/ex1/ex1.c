// 2415 - Consecutivos
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int ultimo;
    int count = 1;
    int pontos = 0;
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        if(i == 0){
            ultimo = x;
            continue;
        }
        if(x == ultimo){
            count++;

        }else{
            if(count > pontos){
                pontos = count;
            }
            count = 1;
        } 
        ultimo = x;
    }
    if(count > pontos){
        pontos = count;
    }

    printf("%d\n", pontos);

    return 0;
}
