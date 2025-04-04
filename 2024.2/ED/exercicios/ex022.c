// Lista 5 - C - Computer Game
#include <stdio.h>

int main(){
  int t;
  scanf("%d", &t);

  for(int i = 0; i < t; i++){
    int n;
    scanf("%d", &n);

    char l1[n + 1];
    char l2[n + 1];
    
    scanf("%s", l1);
    scanf("%s", l2);

    int found = 0;
    for(int j = 0; j < n; j++){
      if(l1[j] == '1' && l2[j] == '1'){
        found = 1;
      }
    }

    if(found){
      printf("NO\n");
    }else{
      printf("YES\n");
    }
  }

  return 0;
}

