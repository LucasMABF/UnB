// Lista 06 - 2253 - Validador de Senhas
#include <stdio.h>

int main(){
    char senha[100];
    while(scanf("%[^\n]", senha) != EOF){
        getchar(); // get rid of \n
        int invalida = 0, maiuscula = 0, minuscula = 0, numero = 0;
        int i;
        for(i = 0; senha[i] != '\0'; i++){
            if(senha[i] >= 'A' && senha[i] <= 'Z'){
                maiuscula = 1;
            }else if(senha[i] >= 'a' && senha[i] <= 'z'){
                minuscula = 1;
            }else if(senha[i] >= '0' && senha[i] <= '9'){
                numero = 1;
            }else{
                invalida = 1;
            }
        }

        if(i < 6 || i > 32 || ! maiuscula || ! minuscula || ! numero){
            invalida = 1;
        }

        if(invalida){
            printf("Senha invalida.\n");
        }else{
            printf("Senha valida.\n");
        }
    }

    return 0;
}
