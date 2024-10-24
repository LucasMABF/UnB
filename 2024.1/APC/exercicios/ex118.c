// Lista 09 - 1028 - Figurinhas
#include <stdio.h>

int mdc(int a, int b){
    if(b == 0){
        return a;
    }
    int c = a % b;
    return mdc(b, c);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int f1, f2;
        scanf("%d %d", &f1, &f2);

        printf("%d\n", mdc(f1, f2));
    }

    return 0;
}
