// Lista 06 - 1581 - Conversa Internacional
#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int pessoas;
        scanf("%d", &pessoas);

        char idioma[21];
        char ultimo[21] = "";
        int diferente = 0;
        for(int j = 0; j < pessoas; j++){
            scanf("%s", idioma);
            if(strcmp(idioma, ultimo) && j > 0){
                diferente = 1;
            }
            strcpy(ultimo, idioma);
        }

        if(diferente){
            printf("ingles\n");
        }else{
            printf("%s\n", ultimo);
        }
    }

    return 0;
}
