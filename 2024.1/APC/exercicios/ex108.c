// Lista 08 - 2633 - Churras no Yuri
#include <stdio.h>

typedef struct carne{
    char nome[20];
    int validade;
} carne;

void sort(carne *lista, int n) {
  int sorted = 0;
  while (!sorted) {
    sorted = 1;
    for (int i = 0; i < n - 1; i++) {
      if (lista[i + 1].validade < lista[i].validade) {
        sorted = 0;
        carne temp = lista[i + 1];
        lista[i + 1] = lista[i];
        lista[i] = temp;
      }
    }
  }
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){

        carne lista[n];
        for(int i = 0; i < n; i++){
            scanf("%s %d", lista[i].nome, &lista[i].validade);
        }

        sort(lista, n);
        
        for(int i = 0; i < n; i++){
            printf("%s", lista[i].nome);
            if(i != n - 1){
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
