// Lista 09 - 2769 - Linha de Montagem
#include <stdio.h>

int menor_tempo(int *linha1, int *linha2, int *troca1, int *troca2, int n, int opcao, int memo[][2]){
    int result;
    if(n == 1){
        if(opcao == 2){
            return linha2[0];
        }else{
            return linha1[0];
        }
    }

    if(memo[n - 2][opcao - 1] != -1){
        return memo[n - 2][opcao - 1];

    }

    int teste1;
    int teste2;
    if(opcao == 1){
        teste1 = linha1[0] + menor_tempo(linha1 + 1, linha2 + 1, troca1 + 1, troca2 + 1, n - 1, opcao, memo);
        teste2 = linha1[0] + troca1[0] + menor_tempo(linha1 + 1, linha2 + 1, troca1 + 1, troca2 + 1, n - 1, 2, memo);
    }else{
        teste1 = linha2[0] + menor_tempo(linha1 + 1, linha2 + 1, troca1 + 1, troca2 + 1, n - 1, opcao, memo);
        teste2 = linha2[0] + troca2[0] + menor_tempo(linha1 + 1, linha2 + 1, troca1 + 1, troca2 + 1, n - 1, 1, memo);
    }

    if(teste1 < teste2){
        result = teste1;
    }else{
        result = teste2;
    }

    memo[n - 2][opcao - 1] = result;
    return result;
}

int main(){
    while(1){
        int n;
        if(scanf("%d", &n) == EOF) break;

        int entrada[2];
        scanf("%d %d", &entrada[0], &entrada[1]);

        int linha1[n];
        for(int i = 0; i < n; i++){
            scanf("%d", &linha1[i]);
        }

        int linha2[n];
        for(int i = 0; i < n; i++){
            scanf("%d", &linha2[i]);
        }

        int troca1[n-1];
        for(int i = 0; i < n - 1; i++){
            scanf("%d", &troca1[i]);
        }
        
        int troca2[n-1];
        for(int i = 0; i < n - 1; i++){
            scanf("%d", &troca2[i]);
        }

        int saida[2];
        scanf("%d %d", &saida[0], &saida[1]);
        linha1[0] += entrada[0];
        linha2[0] += entrada[1];
        linha1[n - 1] += saida[0];
        linha2[n - 1] += saida[1];

        int memo[n - 1][2];
        for(int i = 0; i < n -1; i++){
            memo[i][0] = -1;
            memo[i][1] = -1;
        }

        int resultado1 = menor_tempo(linha1, linha2, troca1, troca2, n, 1, memo);
        int resultado2 = menor_tempo(linha1, linha2, troca1, troca2, n, 2, memo);

        if(resultado1 < resultado2){
            printf("%d\n", resultado1);
        }else{
            printf("%d\n", resultado2);
        }
    }

    return 0;
}
