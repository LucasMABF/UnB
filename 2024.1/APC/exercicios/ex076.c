// Lista 05 - 2386 - Telescópio
#include <stdio.h>

int main(){
    int mm;
    scanf("%d", &mm);

    int n;
    scanf("%d", &n);

    int vistas = 0;
    for(int i = 0; i < n; i++){
        int estrela;
        scanf("%d", &estrela);
        if(estrela * mm >= 40000000){
            vistas++;
        }
    }

    printf("%d\n", vistas);

    return 0;
}
