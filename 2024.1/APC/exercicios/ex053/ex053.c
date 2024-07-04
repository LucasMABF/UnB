// Lista 03 - 1142 - PUM
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int c = 0;
    for(int i = 1, j = 0;; i++){
        if(i % 4 == 0){
            printf("PUM\n");
            c++;
        }else{
            printf("%d ", i);
        }

        if(c == n)break;        
    }

    return 0;
}
