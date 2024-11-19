#include <stdio.h>

int main(){
  int a, b;
  scanf("%d %d", &a, &b);

  if(a > b){
    printf("%d\n%d\n", a, b);
  }else{
    printf("%d\n%d\n", b, a);
  }

  if(a == b){
    printf("iguais\n");
  }else{
    printf("diferentes\n");
  }

  return 0;
}

