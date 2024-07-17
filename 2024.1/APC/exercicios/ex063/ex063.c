// Lista 04 - 4 - Lista PDF Funções 2
#include <stdio.h>

int maior(int a, int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

int menor(int a, int b){
    if(a < b){
        return a;
    }else{
        return b;
    }
}

void maior_e_menor(int *a, int *b, int *c){
    int maior_n = maior(*a, maior(*b, *c));
    int menor_n = menor(*a, menor(*b, *c));
    *a = maior_n;
    *b = menor_n;
}

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    maior_e_menor(&a, &b, &c);
    printf("maior: %d\n", a);
    printf("menor: %d\n", b);

    return 0;
}
