// 1144 - Sequência Lógica
#include <stdio.h>

int main(){
    // 00 01 00 01 00 01 00 01 00 
    // 01 02 01 04 01 06 01 08 01 
    // 01 06 01 18 01 36 01 60 01
    // +12 +18 +24 
    int n;
    scanf("%d", &n);
    n *= 2;
    
    int a = 1;
    int b = 1;
    int c = 1;
    int somador = 0;
    int somador_somador = 6;
    for(int i = 0; i < n; i++){
        printf("%d %d %d\n", a, b, c);
        if(i % 2 == 0){
            b += 1;
            c += 1;
        }else{
            a++;
            b += i + 1;
            somador += somador_somador;
            somador_somador += 6;
            c += somador;
        }
    }

    return 0;
}
