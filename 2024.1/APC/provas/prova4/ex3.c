// 1244 - Ordenação por Tamanho
// na lista 10
#include <stdio.h>
#include <string.h>

int main(){
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    char palavras[50][51];
    int order[50];
    int m = 0;
    while(1){
      scanf("%s", palavras[m]);
      order[m] = m;
      m++;
      if(getchar() == '\n') break;
    }
    
    int sorted = 0;
    while(! sorted){
      sorted = 1;
      for(int k = 1; k < m; k++){
        if(strlen(palavras[order[k - 1]]) < strlen(palavras[order[k]])){
          sorted = 0;
          int tmp = order[k - 1];
          order[k - 1] = order[k];
          order[k] = tmp;
        }
      }
    }

    for(int k = 0; k < m; k++){
      printf("%s", palavras[order[k]]);
      if(k != m - 1){
        printf(" ");
      }
    }

    printf("\n");
  }

  return 0;
}

