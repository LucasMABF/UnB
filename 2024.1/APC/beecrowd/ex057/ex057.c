// 1157 - Divisores I
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= (n / 2); i++){
        if(n % i == 0){
            printf("%d\n", i);
        }
    }
    printf("%d\n", n);

    return 0;
}
