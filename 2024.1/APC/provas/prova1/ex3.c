// 2286 - Par ou Ímpar
#include <stdio.h>

int main(){
    int c = 1;
    while(1){
        int n;
        scanf("%d", &n);
        if(n == 0){
            break;
        }
        printf("Teste %d\n", c);

        char nome1[11];
        char nome2[11];
        scanf("%s", nome1);
        scanf("%s", nome2);

        for(int i = 0; i < n; i++){
            int j1, j2;
            scanf("%d %d", &j1, &j2);
            if((j1 + j2) % 2 == 0){
                printf("%s\n", nome1);
            }else{
                printf("%s\n", nome2);
            }
        }

        printf("\n");
        c++;
    }

    return 0;
}
