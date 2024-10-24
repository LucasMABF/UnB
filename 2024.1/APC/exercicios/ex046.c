// Lista 03 - 1095 - Sequencia IJ 1
#include <stdio.h>

int main(){
    for(int j = 60, i = 1; j >= 0; j -= 5, i += 3){
        printf("I=%d J=%d\n", i, j);
    }

    return 0;
}
