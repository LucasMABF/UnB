// Lista 4 - A - 2D Array - DS
#include <stdio.h>

int main(){
  int matrix[6][6];

  for(int i = 0; i < 6; i++){
    for(int j = 0; j < 6; j++){
      scanf("%d", &matrix[i][j]);
    }
  }

  int maior;
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      int sum = matrix[i][j]  
        + matrix[i][j + 1] 
        + matrix[i][j + 2]
        + matrix[i + 1][j + 1]
        + matrix[i + 2][j]
        + matrix[i + 2][j + 1]
        + matrix[i + 2][j + 2];
      
      if(i == 0 && j == 0){
        maior = sum;
      }else if(sum > maior){
        maior = sum;
      }
    }
  }

  printf("%d\n", maior);

  return 0;
}

