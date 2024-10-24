// 3097 - Um Desafio Simples
#include <stdio.h>

int main(){
    int n, q;
    scanf("%d %d", &n, &q);

    int array[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }

    for(int i = 0; i < q; i++){
        int comando;
        scanf("%d", &comando);

        if(comando == 1){
            int a, y;
            scanf("%d %d", &a, &y);
            a--;
            
            array[a] = y;
        }else{
            int x, a, b;
            scanf("%d %d %d", &x, &a, &b);
            a--;
            b--;

            int count = 0;
            for(; a <= b; a++){
                if(array[a] > x){
                    count++;
                }
            }

            printf("%d\n", count);
        }
    }


    return 0;
}
