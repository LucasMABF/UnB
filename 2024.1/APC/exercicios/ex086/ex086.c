// Lista 06 - 1273 - Justificador
#include <stdio.h>
#include <string.h>

int main(){
    int first = 1;
    while(1){
        int n;
        scanf("%d", &n);
        if(n == 0)break;
        if(!first){
            printf("\n");
        }
        first = 0;
        char palavras[n][51];
        int maior = 0;
        for(int i = 0; i < n; i++){
            scanf("%s", palavras[i]);
            int lidos = strlen(palavras[i]);
            if(lidos > maior) maior = lidos;
        }

        for(int i = 0; i < n; i++){
            int len = strlen(palavras[i]);
            for(int j = 0; j < maior - len; j++){
                printf(" ");
            }
            printf("%s\n", palavras[i]);
        }
    }
    return 0;
}
