// Lista 4 - B - Arrays: Left Rotation
#include <stdio.h>

int main(){
  int n, d;
  scanf("%d %d", &n, &d);

  int arr[n];
  for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }

  for(int i = 0; i < d; i++){
    int tmp = arr[0];
    for(int j = 1; j < n; j++){
      arr[j - 1] = arr[j];
    }
    arr[n - 1] = tmp;
  }

  for(int i = 0; i < n; i++){
    if(i != 0) printf(" ");
    printf("%d", arr[i]);
  }

  return 0;
}

