// Lista 2 - C - the-birthday-bar
#include <stdio.h>

int main(){
  int n;
  scanf("%d", &n);
  
  int bar[n];
  for(int i = 0; i < n; i++){
    scanf("%d", &bar[i]);
  }

  int d, m;
  scanf("%d %d", &d, &m);

  int result = 0;
  for(int i = 0; i < n; i++){
    int sum = 0;
    for(int j = i; j < i + m; j++){
      sum += bar[j];
    }

    if(sum == d){
      result++;
    }

  }

  printf("%d\n", result);


  return 0;
}

