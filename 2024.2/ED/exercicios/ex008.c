// Lista 2 - D - angry-professor
#include <stdio.h>

int main(){
  int t;
  scanf("%d", &t);
  for(int i = 0; i < t; i++){
    int n, k;
    scanf("%d %d", &n, &k);
    
    for(int j = 0; j < n; j++){
      int a;
      scanf("%d", &a);
      if(a <= 0) k--;
    }

    if(k <= 0){
      printf("NO\n");
    }else{
      printf("YES\n");
    }
  }

  return 0;
}

