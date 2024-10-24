// Lista 1 - B - plus-minus
#include <stdio.h>

int main(){
  int n;
  scanf("%d", &n);
  
  int pos = 0;
  int neg = 0;
  int zer = 0;
  for(int i = 0; i < n; i++){
    int x;
    scanf("%d", &x);
    if(x > 0){
      pos++;
    }else if(x < 0){
      neg++;
    }else{
      zer++;
    }
  }

  printf("%lf\n", (double) pos / n);
  printf("%lf\n", (double) neg / n);
  printf("%lf\n", (double) zer / n);

  return 0;
}

