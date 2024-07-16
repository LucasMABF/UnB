// Lista 05 - 1129 - Leitura Ótica
#include <stdio.h>

int main(){
    while(1){
        int n;
        char resposta;
        scanf("%d", &n);
        if(n == 0){
            break;
        }
        for(int i = 0; i < n; i++){
            int respostas[5];
            scanf("%d %d %d %d %d", &respostas[0], &respostas[1], &respostas[2], &respostas[3], &respostas[4]);

            resposta = '\0';
            for(int j = 0; j < 5; j++){
                if(resposta != '\0'){
                    if(respostas[j] <= 127){
                        resposta = '*';
                    }
                }else{
                    if(respostas[j] <= 127){
                        resposta = 65 + j;
                    }
                }
            }

            if(resposta == '\0'){
                resposta = '*';
            }
            
            printf("%c\n", resposta);
        }

    }

    return 0;
}