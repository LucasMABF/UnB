// Lista 3 - B - Sherlock and Array
#include <stdio.h>

int main(){
  int t;
  scanf("%d", &t);
  
  for(int i = 0; i < t; i++){
    int n;
    scanf("%d", &n);

    int arr[n];
    int sum_r = 0;
    for(int j = 0; j < n; j++){
      scanf("%d", &arr[j]);
      sum_r += arr[j];
    }

    int yes = 0;
    int sum_l = 0;
    for(int j = 0; j < n; j++){
      sum_r -= arr[j];
      if(sum_l == sum_r){
        yes = 1;
        break;
      }

      sum_l += arr[j];
    }

    if(yes){
      printf("YES\n");
    }else{
      printf("NO\n");
    }

  }

  return 0;
}

