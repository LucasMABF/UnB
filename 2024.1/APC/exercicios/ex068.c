// Lista 05 - 1172 - Substituição em Vetor I
# include <stdio.h>

int main(){
    int vec[10];
    for(int i = 0; i < 10; i++){
        int n;
        scanf("%d", &n);
        if(n <= 0){
            n = 1;
        }
        vec[i] = n;
    }

    for(int i = 0; i < 10; i++){
        printf("X[%d] = %d\n", i, vec[i]);
    }

    return 0;
}
