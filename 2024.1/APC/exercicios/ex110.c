// Lista 08 - 2729 - Lista de Compras
#include <stdio.h>
#include <string.h>

int add(char *produto, char lista[][21], int n){
    for(int i = 0; i < n; i++){
        if(strcmp(lista[i], produto) == 0){
            return 0;
        }
    }

    strcpy(lista[n], produto);
    return 1;
}

void sort(char lista[][21], int n){
    int sorted = 0;
    while(!sorted){
        sorted = 1;
        for(int i = 0; i < n - 1; i++){
            if(strcmp(lista[i], lista[i + 1]) > 0){
                char temp[21];
                strcpy(temp, lista[i]);
                strcpy(lista[i], lista[i + 1]);
                strcpy(lista[i + 1], temp);
                sorted = 0;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){

        char lista[1000][21];
        int len = 0;
        int j = 0;
        while(1){
            char produto[21];
            scanf("%s", produto);
            len += add(produto, lista, len);
            if(getchar() == '\n'){
                break;
            }
            j++;
        }

        sort(lista, len);

        for(int j = 0; j < len; j++){
            printf("%s", lista[j]);
            if(j != len - 1){
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}
