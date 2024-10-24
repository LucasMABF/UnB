// Lista 2 - A - two-characters
#include <stdio.h>

int main(){
  int n;
  scanf("%d", &n);

  char s[n + 1];
  scanf("%s", s);

  char set[n];
  int set_n = 0;
  for(int i = 0; i < n; i ++){
    int found = 0;
    for(int j = 0; j < set_n; j++){
      if(s[i] == set[j]){
        found = 1;
      }
    }
    if(! found){
      set[set_n] = s[i];
      set_n++;
    }
  }
  
  int result = 0;
  for(int i = 0; i < set_n; i++){
    for(int j = i + 1; j < set_n; j++){
      char t[n + 1];
      int index = 0;
      for(int k = 0; k < n; k++){
        if(s[k] == set[i] || s[k] == set[j]){
          t[index] = s[k];
          index++;
        }
      }
      t[index] = '\0';


      int valido = 1;
      for(int k = 1; k < index; k++){
        if(t[k] == t[k - 1]){
          valido = 0;
        }
      }

      if(valido && index > result){
        result = index;
      }
    }
  }


  printf("%d\n", result);

  return 0;
}

