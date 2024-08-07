// Lista 08 - 1258 - Camisetas
#include <stdio.h>
#include <string.h>

typedef struct camiseta{
    char cor[9];
    char tamanho;
    char nome[100];
} camiseta;

void sort(camiseta *lista, int n) {
  int sorted = 0;
  while (!sorted) {
    sorted = 1;
    for (int i = 0; i < n - 1; i++) {
        int teste = strcmp(lista[i].cor, lista[i + 1].cor);
        if(teste > 0) {
            sorted = 0;
            camiseta temp = lista[i + 1];
            lista[i + 1] = lista[i];
            lista[i] = temp;
        }else if(teste == 0){
            if(lista[i].tamanho < lista[i + 1].tamanho){
                sorted = 0;
                camiseta temp = lista[i + 1];
                lista[i + 1] = lista[i];
                lista[i] = temp;
            }else if(lista[i].tamanho == lista[i + 1].tamanho){
                if(strcmp(lista[i].nome, lista[i + 1].nome)> 0){
                    sorted = 0;
                    camiseta temp = lista[i + 1];
                    lista[i + 1] = lista[i];
                    lista[i] = temp;
                }
            }
        }
    }
  }
}

int main(){
    int primeiro = 1;
    while(1){
        int n;
        scanf("%d", &n);
        if(n == 0){
            break;
        }

        if(! primeiro){
            printf("\n");

        }
        primeiro = 0;
        
        camiseta lista[n];
        for(int i = 0; i < n; i++){
            getchar();
            scanf("%[^\n]", lista[i].nome);
            scanf("%s", lista[i].cor);
            getchar();
            lista[i].tamanho = getchar();
        }

        sort(lista, n);

        for(int i = 0; i < n; i++){
            printf("%s %c %s\n", lista[i].cor, lista[i].tamanho, lista[i].nome);
        }

    }

    return 0;
}
