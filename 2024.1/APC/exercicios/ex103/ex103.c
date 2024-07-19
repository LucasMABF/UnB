// Lista 07 - 2163 - O Despertar da Força
#include <stdio.h>
int SIDES[8][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    
    int terreno[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &terreno[i][j]);
        }
    }


    int x = 0, y = 0;
    for(int i = 1; i < n - 1; i++){
        for(int j = 1; j < m - 1; j++){
            if(terreno[i][j] == 42){
                int sabre = 1;
                for(int k = 0; k < 8; k++){
                    int ty = i + SIDES[k][1];
                    int tx = j + SIDES[k][0];
                    if(terreno[ty][tx] != 7){
                        sabre = 0;
                    }
                }
                if(sabre){
                    x = j + 1;
                    y = i + 1;
                    break;
                }
            }
        }
    }

    printf("%d %d\n", y, x);

    return 0;
}
