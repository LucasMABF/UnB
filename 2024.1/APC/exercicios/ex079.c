// Lista 05 - 2779 -Álbum da Copa
#include <stdio.h>

int main(){
    int n_figurinhas;
    scanf("%d", &n_figurinhas);
    int album[n_figurinhas];
    for(int i = 0; i < n_figurinhas; i++){
        album[i] = 1;
    }

    int n_compradas;
    scanf("%d", &n_compradas);
    for(int i; i < n_compradas; i++){
        int figurinha;
        scanf("%d", &figurinha);
        album[figurinha - 1] = 0;
    }

    int restantes = 0;
    for(int i; i < n_figurinhas; i++){
        restantes += album[i];
    }

    printf("%d\n", restantes);

    return 0;
}
