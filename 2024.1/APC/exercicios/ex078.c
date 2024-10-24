// Lista 05 - 2715 - Dividindo os Trabalhos I
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        int trabalhos[n];
        long long int gugu = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &trabalhos[i]);
            gugu += trabalhos[i];
        }

        long long int rangel = 0;
        long long int dif;
        long long int resposta = gugu - rangel;
        for(int i = 0; i < n; i++){
            dif = llabs(gugu - rangel);
            if(dif < resposta){
                resposta = dif;
            }
            rangel += trabalhos[i];
            gugu -= trabalhos[i];

        }

        printf("%lld\n", resposta);

    }

    return 0;
}
