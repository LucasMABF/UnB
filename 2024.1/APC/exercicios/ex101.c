// Lista 07 - 1618 - Colisão
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy, Rx, Ry;
        scanf("%d %d %d %d %d %d %d %d %d %d", &Ax, &Ay, &Bx, &By, &Cx, &Cy, &Dx, &Dy, &Rx, &Ry);
        if(Rx >= Ax && Rx <= Bx && Ry >= Ay && Ry <= Dy){
            printf("1\n");
        }else{
            printf("0\n");
        }
    }

    return 0;
}
