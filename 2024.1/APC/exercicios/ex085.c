// Lista 06 - 1272 - Mensagem Oculta
#include <stdio.h>

int main(){
    int n;
    scanf("%d ", &n);

    for(int i = 0; i < n; i++){
        int first = 1;
        while(1){
            char c;
            c = getchar();
            if(c == '\n' || c == EOF) break;
            if(c != ' '){
                if(first){
                    printf("%c", c);
                    first = 0;
                }
            }else{
                first = 1;
            }
        }
        printf("\n");
    }

    return 0;
}
