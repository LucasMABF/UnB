// Lista 5 - D - Gold Rush
#include <stdio.h>

int calculate(int n, int m){
  if(n == m){
    return 1;
  }else if(n < m){
    return 0;
  }
  float a = (2.0/3.0) * n;
  float b = (1.0/3.0) * n;
  if(a - (int) a == 0 && b - (int) b == 0){
    if(a == m || b == m){
      return 1;
    }
    return calculate(a, m) || calculate(b, m);
  }else{
    return 0;
  }
}

int main(){
  int t;
  scanf("%d", &t);
  
  for(int i = 0; i < t; i++){
    int n, m;
    scanf("%d %d", &n, &m);
    
    int result = calculate(n, m);

    if(result){
      printf("YES\n");
    }else{
      printf("NO\n");
    }
  }

  return 0;
}

