// Lista 05 - 2782 - Escadinha
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int ultimo;
    int n_escadinhas = 0;
    int passo;
    for(int i = 0; i < n; i++){
        int atual;
        scanf("%d", &atual);
        if(i == 0){
            ultimo = atual;
        }
        else if(i == 1){
            passo = atual - ultimo;
            ultimo = atual;
        }else if(atual - ultimo == passo){
            ultimo = atual;
        }else{
            passo = atual - ultimo;
            ultimo = atual;
            n_escadinhas++;
        }
        if(i == n - 1){
            passo = atual - ultimo;
            ultimo = atual;
            n_escadinhas++;
        }
    }
    printf("%d\n", n_escadinhas);
    return 0;
}
