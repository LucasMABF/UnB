// Lista 06 - 2712 - Rodízio Veicular
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    getchar(); // get rid of \n

    for(int i = 0; i < n; i++){
        char placa[101];
        scanf("%[^\n]", placa);
        getchar(); // get rid of \n
        int invalid = 0;
        int j;
        for(j = 0;; j++){
            if(j < 3){
                if(placa[j] > 'Z' || placa[j] < 'A'){
                    invalid = 1;
                }
            }else if(j == 3){
                if(placa[j] != '-'){
                    invalid = 1;
                }
            }else if(j < 8){
                if(placa[j] > '9' || placa[j] < '0'){
                    invalid = 1;
                }
            }else if(j == 8){
                if(placa[j] != '\0'){
                    invalid = 1;
                }
                break;
            }
        }

        if(invalid){
            printf("FAILURE\n");
        }else{
            switch (placa[j - 1]){
                case '1':
                case '2':
                    printf("MONDAY\n");
                    break;
                case '3':
                case '4':
                    printf("TUESDAY\n");
                    break;
                case '5':
                case '6':
                    printf("WEDNESDAY\n");
                    break;
                case '7':
                case '8':
                    printf("THURSDAY\n");
                    break;
                case '9':
                case '0':
                    printf("FRIDAY\n");
                    break;
            }

        }
    }

    return 0;
}
