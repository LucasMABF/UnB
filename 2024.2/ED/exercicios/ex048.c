// Lista 10 - D - Save More Mice
#include <stdio.h>

void merge(int *arr, int left, int mid, int right){
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int L[n1];
  int R[n2];

  for(int i = 0; i < n1; i++){
    L[i] = arr[left + i];
  }

  for(int i = 0; i < n1; i++){
    R[i] = arr[mid + i + 1];
  }

  int i = 0;
  int j = 0;
  int k = left;

  while(i < n1 && j < n2){
    if(L[i] >= R[j]){
      arr[k] = L[i];
      i++;
    }else{
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while(i < n1){
    arr[k] = L[i];
    i++;
    k++;
  }

  while(j < n2){
    arr[k] = R[j];
    j++;
    k++;
  }
}

void merge_sort(int *arr, int left, int right){
  if(left < right){
    int mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}

int main(){
  int t;
  scanf("%d", &t);
  
  for(int i = 0; i < t; i++){
    int n, k;
    scanf("%d %d", &n, &k);

    int mice[k];
    for(int j = 0; j < k; j++){
      scanf("%d", &mice[j]);
    }

    merge_sort(mice, 0, k - 1);

    int result = 0;
    int counter_cat = 0;
    for(int j = 0; j < k; j++){
        counter_cat += n - mice[j];
      if(counter_cat < n){
        result++;
      }else{
        break;
      }
    }

    printf("%d\n", result);
  }

  return 0;
}

