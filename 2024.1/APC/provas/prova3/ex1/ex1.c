// 1608 - Bolos da Maria
#include <stdio.h>

int main(){
    int t;
    scanf("%d", &t);

    for(int j = 0; j < t; j++){
        int d, i, b;
        scanf("%d %d %d", &d, &i, &b);

        int precos[i];
        for(int k = 0; k < i; k++){
            scanf("%d", &precos[k]);
        }

        int quantidade_bolos = 0;
        for(int k = 0; k < b; k++){
            int n_ingredientes;
            scanf("%d", &n_ingredientes);

            int preco = 0;
            for(int l = 0; l < n_ingredientes; l++){
                int ing, quant;
                scanf("%d %d", &ing, &quant);
                preco += quant * precos[ing];
            }

            int teste = d / preco;
            if(teste > quantidade_bolos){
                quantidade_bolos = teste;
            }
        }

        printf("%d\n", quantidade_bolos);
    }

    return 0;
}
