// 3558 - Sobrenome Não é Fácil
#include <stdio.h>
#include <string.h>

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    char nome[43];
    scanf("%s", nome);

    int size = strlen(nome);
    int count = 0;
    int dificil = 0;
    for(int j = 0; j < size; j++){
      char vogais[] = "AEIOUaeiou";
      int consoante = 1;
      for(int k = 0; k < 10; k++){
        if(nome[j] == vogais[k]){
          consoante = 0;
          count = 0;
          break;
        }
      }

      if(consoante){
        count++;
        if(count >= 3){
          dificil = 1;
          break;
        }
      }
    }

    if(dificil){
      printf("%s nao eh facil\n", nome);
    }else{
      printf("%s eh facil\n", nome);
    }
  }

  return 0;
}
