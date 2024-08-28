// 2855 - Números de Sorte
#include <stdio.h>
#include <stdlib.h>

int *remove_item(int *list, int size, int index){
    for(int i = 0; i < size; i++){
        if((i + 1) % index == 0){
            list[i] = -1;
        }
    }
    int n = (int) size - (size / index);
    int *new = malloc(n * sizeof(int));
    int idx = 0;
    for(int i = 0; i < n; i++){
        while(list[idx] < 0 && idx < size){
            idx++;
        }
        new[i] = list[idx];
        idx++;
    }
    free(list);
    return new;
}

int main(){
    while(1){
        int n;
        if(scanf("%d", &n) == EOF) break;

        int *numeros = malloc(n * sizeof(int));
        for(int i = 0; i < n; i++){
            scanf("%d", &numeros[i]);
        }

        int m;
        scanf("%d", &m);
        int count = 2;
        while(1){
            numeros = remove_item(numeros, n, count);
            n -= (n / count);

            count++;

            int yes = 0;
            int not_found = 1;
            for(int i = 0; i < n; i++){
                if(m == numeros[i]){
                    not_found = 0;
                    if(i < count - 1){
                        yes = 1;
                    }
                    break;
                }
            }

            if(yes) {
                printf("Y\n");
                break;
            }else if(not_found){
                printf("N\n");
                break;
            }
        
        }
    }

    return 0;
}
