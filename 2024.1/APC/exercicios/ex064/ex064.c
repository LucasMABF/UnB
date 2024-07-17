// Lista 04 - 5 - Lista PDF Funções 2
#include <stdio.h>

void switch_values(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    for(int i = 0; i < 5; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        switch_values(&x, &y);
        printf("x = %d y = %d\n", x, y);
    }

    return 0;
}
