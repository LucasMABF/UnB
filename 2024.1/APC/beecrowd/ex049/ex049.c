// 1114 - Senha Fixa
#include <stdio.h>
#include <string.h>

int main(){
    while(1){
        char senha[10];
        scanf("%s", senha);

        if(strcmp(senha, "2002") == 0){
            printf("Acesso Permitido\n");
            break;
        }else{
            printf("Senha Invalida\n");
        }
    }

    return 0;
}
