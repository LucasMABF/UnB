// 2415 - Consecutivos
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int count = 1;
    int maior_count = 1;
    for(int i = 0; i < n; i++){
        int x;
        int ultimo;
        scanf("%d", &x);
        if(i > 0){
            if(x == ultimo){
                count++;
            }else{
                if(count > maior_count){
                    maior_count = count;
                }
                count = 1;
            }
        }
        ultimo = x;
    }
    if(count > maior_count){
        maior_count = count;
    }

    printf("%d\n", maior_count);
}
