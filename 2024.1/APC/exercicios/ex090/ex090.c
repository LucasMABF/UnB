// Lista 06 - 2635 - Navegador Web
#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);

    char pesquisas[n][100];
    for(int i = 0; i < n; i++){
        scanf("%s", pesquisas[i]);
    }

    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        char consulta[100];
        scanf("%s", consulta);

        int resultados = 0;
        int maior = 0;
        for(int j = 0; j < n ; j++){
            int match = 1;
            for(int k = 0; consulta[k] != '\0'; k++){
                if(consulta[k] != pesquisas[j][k]){
                    match = 0;
                }
            }
            if(match){
                resultados++;
                if(strlen(pesquisas[j]) > maior){
                    maior = strlen(pesquisas[j]);
                }
            }
        }

        if(resultados == 0){
            printf("-1\n");
        }else{
            printf("%d %d\n", resultados, maior);
        }
    }

    return 0;
}
