// Lista 10 - B - Choosing Cubes
#include <stdio.h>
#include <stdlib.h>


int compare(const void *a, const void *b){
  return *(int*)b - *(int*)a;
}

int main(){
  int t;
  scanf("%d", &t);
  
  for(int i = 0; i < t; i++){
    int n, f, k;
    scanf("%d %d %d", &n, &f, &k);

    int arr[n];
    for(int j = 0; j < n; j++){
      scanf("%d", &arr[j]); 
    }
    int fav = arr[f - 1];

    qsort(arr, n, sizeof(int), compare);

    if(k == n){
      printf("YES\n");
    }else if(arr[k] > fav){
      printf("NO\n");
    }else if(arr[k] < fav){
      printf("YES\n");
    }else{
      if(arr[k - 1] == fav){
        printf("MAYBE\n");
      }else{
        printf("NO\n");
      }
    }
    
  }
  
  return 0;
}

