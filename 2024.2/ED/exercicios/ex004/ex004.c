// Lista 1 - E - cats-and-a-mouse
#include <stdio.h>
#include <stdlib.h>

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);

    int d1 = abs(x - z);
    int d2 = abs(y - z);

    if(d1 < d2){
      printf("Cat A\n");
    }else if(d2 < d1){
      printf("Cat B\n");
    }else{
      printf("Mouse C\n");
    }

  }

  return 0;
}

