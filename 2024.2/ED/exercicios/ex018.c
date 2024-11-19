// Lista 4 - D - CamelCase
#include <stdio.h>
#include <string.h>

int main(){
  char s[100000];
  scanf("%s", s);
  int len = strlen(s);
  
  int result = 1;
  for(int i = 0; i < len; i++){
    if(s[i] <= 'Z'){
      result++;
    }
  }

  printf("%d\n", result);
  return 0;
}

