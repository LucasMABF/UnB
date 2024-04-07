// 1052 - Mês
#include <stdio.h>

int main(){
    char meses[][12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    int n;
    scanf("%d", &n);
    
    if(n <= 12 && n > 0){
        printf("%s\n", meses[n - 1]);
    }

    return 0;
}
