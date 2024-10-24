// Lista 06 - 1848 - Corvo Contador
#include <stdio.h>
#include <math.h>

int main(){
    for(int i = 0; i < 3; i++){

        int soma = 0;
        int end = 0;
        while(1){
            int binario = 0;
            for(int j = 2; j >= 0; j--){
                char c = getchar();
                if(c == '\n' || c == ' '){
                    j++;
                }else if(c == 'c'){
                    end++;
                }else if(c == '*'){
                    binario += pow(2, j);
                }
            }
            soma += binario;
            if(end == 2){
                break;
            }
        }

        printf("%d\n", soma);
    }

    return 0;
}
