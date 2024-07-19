// Lista 07 - 2520 - O Último Analógimôn
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF){
        int Ax, Ay, Vx, Vy;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int x;
                scanf("%d", &x);
                if(x == 1){
                    Vx = j;
                    Vy = i;
                }else if(x == 2){
                    Ax = j;
                    Ay = i;
                }
            }
        }

        printf("%d\n", abs(Ax - Vx) + abs(Ay - Vy));
    }

    return 0;
}
