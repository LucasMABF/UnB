// Lista 06 - 1629 - DescompactaFACE
#include <stdio.h>
#include <math.h>

int soma_digitos(int n){
    int soma = 0;
    for(int i = n; i > 0;){
        int x = i / (int) pow(10, (int)log10(i));
        soma += x;
        i -= x * (int) pow(10, (int) log10(i));
    }

    return soma;
}

int main(){
    int n = 1;
    while(n != 0){
        scanf("%d ", &n);

        for(int i = 0; i < n; i++){
            int soma_pares = 0;
            int soma_impares = 0;
            int count = 0;
            while(1){
                char c = getchar();
                if(c == '\n') break;
                int x = c - 48;
                if(count % 2 == 0){
                    soma_pares += x;
                }else{
                    soma_impares += x;
                }
                count++;
            }

            int resposta = soma_digitos(soma_pares) + soma_digitos(soma_impares);
            printf("%d\n", resposta);
        }
    }
    return 0;
}
