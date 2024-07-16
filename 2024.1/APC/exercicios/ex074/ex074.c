// Lista 05 - 2465 - Passa Bolinha
#include <stdio.h>
int sides[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void passa_bolinha(int n, int alunos[n][n], int bandeiras[n][n], int inicial_y, int inicial_x){
    bandeiras[inicial_y][inicial_x] = 1;
    int atual = alunos[inicial_y][inicial_x];
    for(int i = 0; i < 4; i++){
        int proximo_y = inicial_y - sides[i][0];
        int proximo_x = inicial_x - sides[i][1];
        int proximo = alunos[proximo_y][proximo_x];
        if(proximo_y < n && proximo_y >= 0 && proximo_x < n && proximo_x >= 0){
            if( proximo >= atual && bandeiras[proximo_y][proximo_x] == 0){
                passa_bolinha(n, alunos, bandeiras, proximo_y, proximo_x);
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int alunos[n][n];

    int x, y;
    scanf("%d %d", &y, &x);
    y--;
    x--;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &alunos[i][j]);
        }
    }

    int bandeiras[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            bandeiras[i][j] = 0;
        }
    }
    passa_bolinha(n, alunos, bandeiras, y, x);

    int resultado = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            resultado += bandeiras[i][j];
        }
    }

    printf("%d\n", resultado);
    return 0;
}
