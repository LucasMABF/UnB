// 2242 - Huaauhahhuahau
#include <stdio.h>
#include <string.h>

int main(){
  char risada[51];
  scanf("%s", risada);
  char vogais[51];
  vogais[0] = '\0';

  int size = strlen(risada);
  int idx = 0;
  for(int i = 0; i < size; i++){
    if(risada[i] == 'a' || risada[i] == 'e' || risada[i] == 'i' || risada[i] == 'o' || risada[i] == 'u'){
      vogais[idx] = risada[i];
      vogais[idx + 1] = '\0';
      idx++;
    }
  }

  size = strlen(vogais);
  int simetrico = 1;
  for(int i = 0; i < size / 2; i++){
    if(vogais[i] != vogais[size - 1 - i]){
      simetrico = 0;
    }
  }

  if(simetrico){
    printf("S\n");
  }else{
    printf("N\n");
  }


  return 0;
}

