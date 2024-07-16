// Lista 05 - 1318 - Bilhetes Falsos
#include <stdio.h>

int main(){
    while(1){
        int n, m;
        scanf("%d %d", &n, &m);

        if(n == 0 && m == 0) break;

        int bilhetes[n];
        for(int i = 0; i < n; i++){
            bilhetes[i] = 0;
        }

        for(int i = 0; i < m; i++){
            int x;
            scanf("%d", &x);
            bilhetes[x - 1]++;
        }

        int repetidos = 0;
        for(int i = 0; i < n; i++){
            if(bilhetes[i] > 1){
                repetidos++;
            }
        }

        printf("%d\n", repetidos);
    }

    return 0;
}
