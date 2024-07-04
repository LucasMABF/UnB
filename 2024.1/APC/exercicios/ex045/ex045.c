// Lista 03 - 1094 - Experiências
#include <stdio.h>

int main(){
    int sapos = 0;
    int ratos = 0;
    int coelhos = 0;

    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int x;
        char t;
        scanf("%d %c", &x, &t);
        if(t == 'R'){
            ratos += x;
        }else if (t == 'S'){
            sapos += x;
        }else{
            coelhos += x;
        }
    }

    int total = ratos + sapos + coelhos;
    printf("Total: %d cobaias\n", total);
    printf("Total de coelhos: %d\n", coelhos);
    printf("Total de ratos: %d\n", ratos);
    printf("Total de sapos: %d\n", sapos);
    printf("Percentual de coelhos: %.2lf %%\n", 100.0 * coelhos / total);
    printf("Percentual de ratos: %.2lf %%\n", 100.0 * ratos / total);
    printf("Percentual de sapos: %.2lf %%\n", 100.0 * sapos / total);

    return 0;
}
