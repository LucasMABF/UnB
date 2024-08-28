// 2293 - Campo de Minhocas
#include <stdio.h>

int main(){
    int m, n;
    scanf("%d %d", &m, &n);

    int maior_soma = 0;
    int somas_colunas[n];
    for(int i = 0; i < n; i++){
        somas_colunas[i] = 0;
    }

    for(int i = 0; i < m; i++){
        int soma_linha = 0;
        for(int j = 0; j < n; j++){
            int minhocas;
            scanf("%d", &minhocas);
            soma_linha += minhocas;
            somas_colunas[j] += minhocas;

        }
        if(soma_linha > maior_soma){
            maior_soma = soma_linha;
        }
    }

    for(int i = 0; i < n; i++){
        if(somas_colunas[i] > maior_soma){
            maior_soma = somas_colunas[i];
        }
    }

    printf("%d\n", maior_soma);


    return 0;
}
