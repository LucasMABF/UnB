// Lista 05 - 1973 - Jornada nas Estrelas
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int estrelas[n];

    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        estrelas[i] = x;
    }

    int index = 0;
    int atacadas[n];
    for(int i = 0; i < n; i++){
        atacadas[i] = 0;
    }

    while(1){
        if(atacadas[index] == 0){
            atacadas[index]++;
        }

        if(estrelas[index] % 2 == 0){
            if(estrelas[index] > 0) estrelas[index]--;
            index--;
        }else{
            if(estrelas[index] > 0) estrelas[index]--;
            index++;
        }
        if(index < 0 || index >= n) break;
    }

    long long int sum = 0;
    for(int i = 0; i < n; i++){
        sum += estrelas[i];
    }

    int a = 0;
    for(int i = 0; i < n; i++){
        a += atacadas[i];
    }

    printf("%d %lld\n", a, sum);

    return 0;
}
