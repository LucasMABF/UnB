// Lista 2 - B - divisible-sum-pairs
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
      result += (arr[i] + arr[j]) % k == 0;
    }
  }
  
  printf("%d\n", result);

  return 0;
}

