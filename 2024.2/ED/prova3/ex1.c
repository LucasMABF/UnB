#include <stdio.h>

int findJudge(int N, int trust[][2], int trustSize) {
  int candidatos[N];
  for(int i = 1; i <= N; i++){
    int invalidJudge = 0;
    for(int j = 0; j < trustSize; j++){
      if(trust[j][0] == i){
        invalidJudge = 1;
      }
    }
    if(!invalidJudge){
      candidatos[i - 1] = 1;
    }else{
      candidatos[i - 1] = 0;
    }
  }

  int juiz = -1;
  for(int i = 1; i <= N; i++){
    if(candidatos[i - 1] == 0) continue;

    int valid = 1;
    for(int j = 1; j <= N; j++){
      if(j == i) continue;

      int found = 0;
      for(int k = 0; k < trustSize; k++){
        if(trust[k][0] == j && trust[k][1] == i){
          found = 1;
          break;
        }
      }
      if(!found){
        valid = 0;
      }
    }
    if(valid){
      if(juiz == -1){
        juiz = i;
      }else{
        return -1;
      }
    }

  }

  return juiz;
}

int main(){
  int n;

  scanf("%d", &n);

  int size;
  scanf("%d", &size);

  int confia[size][2];
  for(int i = 0; i < size; i++){
    scanf("%d %d", &confia[i][0], &confia[i][1]);
  }

  int result = findJudge(n, confia, size);

  printf("%d\n", result);

  return 0;
}

