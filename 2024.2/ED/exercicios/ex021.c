// Lista 5 - B - Maximize?
#include <stdio.h>

int gcd(int a, int b){
  int temp; 
  while( b != 0){
    temp = a % b;

    a = b;
    b = temp;
  }
  
  return a;
}

int main(){
  int t;
  scanf("%d", &t);

  for(int i = 0; i < t; i++){
    int n;
    scanf("%d", &n);

    int maior;
    int y;
    for(int j = 1; j < n; j++){
      int g = gcd(j, n) + j;
      if(j == 1){
        maior = g;
        y = j;
      }else if(g > maior){
        maior = g;
        y = j;
      }
    }
    printf("%d\n", y);
  }
  
  return 0;
}

