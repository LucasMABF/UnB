// Lista 5 - E - Transformation: from A to B
#include <stdio.h>

int calculate(int b, int a, int i){

  if(b == a){
    printf("YES\n");
    printf("%d\n", i);
    printf("%d", a);
    return 1;
  }

  if(b < a) return -1;

  if(b % 2 == 0){
    int t1 = b / 2;

    int t3 = calculate(t1, a, i + 1);
    if(t3 > 0){
      printf(" %d", b);
      return 1;
    }
  }

  if((b - 1) % 10 == 0){
    int t2 = (b - 1)/10;
    int t4 = calculate(t2, a, i + 1);
    if(t4 > 0){
      printf(" %d", b);
      return 1;
    }
  }

  return - 1;
}

int main(){
  int a, b;
  scanf("%d %d", &a, &b);

  if(calculate(b, a, 1) < 0){
    printf("NO\n");
  }else{
    printf("\n");
  }

  return 0;
}

