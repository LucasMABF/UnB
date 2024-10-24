// 1047 - Tempo de Jogo com Minutos
#include <stdio.h>

int main(){
    int h1, m1, h2, m2;
    scanf("%d %d %d %d", &h1, &m1, &h2, &m2);

    int h = h2 - h1;
    int m = m2 - m1;

    if(m < 0){
        m += 60;
        h -= 1;
    }

    if(h < 0){
        h += 24;
    }

    if(h == 0 && m == 0){
        h = 24;
        m = 0;
    }

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", h, m);

    return 0;
}
