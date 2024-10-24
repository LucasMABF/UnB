// Lista 05 - 1172 - Preenchimento de Vetor I
#include <stdio.h>

int main(){
    int vec[10];
    int n;
    scanf("%d", &n);
    vec[0] = n;
    for(int i = 1; i < 10; i++){
        vec[i] = vec[i - 1] * 2;
    }

    for(int i = 0; i < 10; i++){
        printf("N[%d] = %d\n", i, vec[i]);
    }
    return 0;
}
