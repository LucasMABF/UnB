// 1046 - Tempo de Jogo
#include <stdio.h>

int main(){
    int i, f;
    scanf("%d %d", &i, &f);

    int tempo = (((f - i) % 24) + 24) % 24;
    if (tempo == 0) tempo = 24;
    printf("O JOGO DUROU %d HORA(S)\n", tempo);

    return 0;
}
