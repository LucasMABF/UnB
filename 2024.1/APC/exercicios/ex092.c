// Lista 06 - 1551 - Frase Completa
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    getchar(); // get rid of \n
    for(int i = 0; i < n; i++){
        char frase[1001];
        scanf("%[^\n]", frase);
        getchar(); // get rid of \n

        int letras = 0;
        char usadas[27];
        usadas[0] = '\0';
        for(int j = 0; frase[j] != '\0';j++){
            if(frase[j] == ',' || frase[j] == ' '){
                continue;
            }
            int usada = 0;
            int k;
            for(k = 0; usadas[k] != '\0'; k++){
                if(frase[j] == usadas[k]){
                    usada = 1;
                }
            }

            if(! usada){
                letras++;
                usadas[k] = frase[j];
                usadas[k + 1] = '\0';
            }
        }

        if(letras == 26){
            printf("frase completa\n");
        }else if(letras >= 13){
            printf("frase quase completa\n");
        }else{
            printf("frase mal elaborada\n");
        }
    }

    return 0;
}
