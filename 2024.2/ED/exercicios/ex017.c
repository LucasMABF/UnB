// Lista 4 - C - Divisible Sum Pairs
#include <stdio.h>

int main(){
  int n, k;
  scanf("%d %d", &n, &k);

  int arr[n];
  for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }

  int result = 0;
  for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
      if((arr[i] + arr[j]) % k == 0){
        result++;
      }
    }
  }

  printf("%d\n", result);

  return 0;
}

