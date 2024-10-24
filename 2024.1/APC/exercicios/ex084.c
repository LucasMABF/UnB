// Lista 06 - 1235 - De Dentro para Fora
#include <stdio.h>

int readln(char *buff){
    char c;
    int index = 0;
    while((c = getchar()) != '\n'){
        buff[index] = c;
        index++;
    }

    buff[index] = '\0';
    return index;
}

int main(){
    int n;
    scanf("%d", &n);
    getchar(); // get rid of \n
    for(int i = 0; i < n; i++){
        char linha[100];
        int len = readln(linha);
        for(int i = (len / 2) - 1; i >= 0; i--){
            printf("%c", linha[i]);
        }
        for(int i = len - 1; i >= (len / 2); i--){
            printf("%c", linha[i]);
        }
        printf("\n");
    }

    return 0;
}
