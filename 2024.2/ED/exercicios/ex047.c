// Lista 10 - C - Symmetric Encoding
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
  return *(char*)a - *(char*)b;
}

int main(){
  int t;
  scanf("%d", &t);
  
  for(int i = 0; i < t; i++){
    int n;
    scanf("%d", &n);
    getchar();

    char s[n];
    char set[n];
    int idx = 0;
    for(int j = 0; j < n; j++){
      s[j] = getchar();
      
      int found = 0;
      for(int k = 0; k < idx; k++){
        if(s[j] == set[k]){
          found = 1;
        }
      }

      if(!found){
        set[idx] = s[j];
        idx++;
      }
    }
    getchar();
    
    qsort(set, idx, sizeof(char), compare);

    char result[n + 1];
    for(int j = 0; j < n; j++){
      for(int k = 0; k < idx; k++){
        if(s[j] == set[k]){
          result[j] = set[(idx - 1) - k];
        }
      }
    }

    result[n] = '\0';
    printf("%s\n", result);

  }
  return 0;
}

