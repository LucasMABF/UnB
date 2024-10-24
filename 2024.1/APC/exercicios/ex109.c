// Lista 08 - 2654 - Godofor
#include <stdio.h>
#include <string.h>

typedef struct godofor{
    char nome[100];
    int poder;
    int matou;
    int morreu;
} godofor;

void troca(godofor *lista, int i){
    godofor temp;
    temp = lista[i];
    lista[i] = lista[i + 1];
    lista[i + 1] = temp;

}

void sort(godofor *lista, int n) {
    int sorted = 0;
    while (!sorted) {
        sorted = 1;
        for (int i = 0; i < n - 1; i++) {
            if(lista[i].poder < lista[i + 1].poder){
                sorted = 0;
                troca(lista, i);
            }else if(lista[i].poder == lista[i + 1].poder){
                if(lista[i].matou < lista[i + 1].matou){
                    sorted = 0;
                    troca(lista, i);
                }else if(lista[i].matou == lista[i + 1].matou){
                    if(lista[i].morreu > lista[i + 1].morreu){
                        sorted = 0;
                        troca(lista, i);
                    }else if(lista[i].morreu == lista[i + 1].morreu){
                        if(strcmp(lista[i].nome, lista[i + 1].nome) > 0){
                            sorted = 0;
                            troca(lista, i);
                        }
                    }
                }

            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);

    godofor lista[n];
    for(int i = 0; i < n; i++){
        scanf("%s %d %d %d", lista[i].nome, &lista[i].poder, &lista[i].matou, &lista[i].morreu);
    }

    sort(lista, n);

    printf("%s\n", lista[0].nome);

    return 0;
}
