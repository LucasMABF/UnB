// Lista 06 - 1192 - O jogo Matemático de Paula
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        char x[4];
        scanf("%s", x);
        int resposta;
        int x1 = x[0] - 48; // 48 to get digit's value from ascii
        int x2 = x[2] - 48;
        if(x1 == x2){
            resposta = x1 * x2;
        }else if(x[1] > 90){ // minusculas
            resposta = x1 + x2;
        }else{
            resposta = x2 - x1;
        }

        printf("%d\n", resposta);
    }

    return 0;
}
