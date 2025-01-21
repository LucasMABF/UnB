// Lista 10 - A - z-sort
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
  return *(int*)a - *(int*)b;
}

int main(){
  int n;
  scanf("%d", &n);

  int arr[n];
  for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }
  
  qsort(arr, n, sizeof(int), compare);

  for(int i = 0, j = 0, k = n - 1; i < n; i++){
    if(i % 2 == 0){
      if(i == 0){
        printf("%d", arr[j]);
      }else{
        printf(" %d", arr[j]);
      }
      j++;
    }else{
      printf(" %d", arr[k]);
      k--;
    }
  }
  printf("\n");
  
  return 0;
}

