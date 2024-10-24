// Lista 01 - 1930 - Tomadas
#include <stdio.h>

int main(){
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    int max = a + b + c + d - 3;

    printf("%d\n", max);

    return 0;
}
