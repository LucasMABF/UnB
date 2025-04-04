// Lista 11 - A - Love Triangle
#include <stdio.h>

int main(){
  int n;
  scanf("%d", &n);

  int plane[n];

  for(int i = 0; i < n; i++){
    scanf("%d", &plane[i]);
    plane[i]--;
  }

  int found = 0;
  for(int i = 0; i < n; i++){
    if(plane[plane[plane[plane[i]]]] == plane[i]){
      found = 1;
      break;
    }
  }

  if(found){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
  
  return 0;
}

