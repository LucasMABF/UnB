// 1079 - Médias Ponderadas
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        double a, b, c;
        scanf("%lf %lf %lf", &a, &b, &c);
        double media = (2 * a + 3 * b + 5 * c) / 10;
        printf("%.1lf\n", media);
    }

    return 0;
}
