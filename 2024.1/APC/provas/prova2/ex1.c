// 2067 - Jogo do Quadrado
#include <stdio.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int matriz[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        int s;
        scanf("%d", &s);

        int yes = 0;
        for(int j = 0; j <= n - s; j++){
            if(yes) break;
            for(int k = 0; k <= m - s; k++){
                int zero = 0;
                for(int l = 0; l < s; l++){
                    if(zero) break;
                    for(int h = 0; h < s; h++){
                        if(matriz[l + j][h + k] == 0){
                            zero = 1;
                            break;
                        }
                    }
                }
                if(! zero){
                    yes = 1;
                    break;
                }
            }
        }

        if(yes) printf("yes\n");
        else printf("no\n");

    }
    return 0;
}
