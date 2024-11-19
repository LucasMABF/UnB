// Lista 3 - C - Binary Search - Advanced
#include <stdio.h>

int main(){
  int n;
  scanf("%d", &n);

  int arr[n];
  for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }

  int x;
  scanf("%d", &x);

  int first = -1;
  int last = -1;
  int occurences = 0;
  int upper = n;
  int lower = 0;
  while(upper > lower){
    int mid = (upper - lower) / 2;
    if(arr[mid] > x){
      upper = mid - 1;
    }else if(arr[mid] < x){
      lower = mid + 1;
    }else{
      occurences++;
      first = mid;
      last = mid;
      int current = mid - 1;
      while(arr[current] == x){
        occurences++;
        current--;
      }
      first = current + 1;
      current = mid + 1;
      while(arr[current] == x){
        occurences++;
        current++;
      }
      last = current - 1;
      break;
    }
  }

  printf("%d %d %d\n", first, last, occurences);

  return 0;
}

