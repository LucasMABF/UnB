// Lista 3 - A - Missing Numbers 
// aborted?
#include <stdio.h>
#include <stdlib.h>

int find_x(int x, int *vec, int size){
  if(size == 0){
    return 0;
  }
  for(int i = 0; i < size; i++){
    if(vec[i] == x){
      return 1;
    }
  }
  return 0;
}

int *remove_x(int x, int *vec, int size){
  if(size == 1){
    free(vec);
    return NULL;
  }
  int *tmp = malloc((size - 1) * sizeof(int));
  if(tmp == NULL){
    printf("error\n");
    exit(1);
  }
  int found = 0;
  for(int i = 0; i < size; i++){
    if(found){
      tmp[i - 1] = vec[i];
    }else{
      if(vec[i] != x){
        tmp[i] = vec[i];
      }else{
        found = 1;
      }
    }
  }

  free(vec);
  return tmp;
}

int main(){
  int n;
  scanf("%d", &n);

  int *arr = malloc(n * sizeof(int));
  if(arr == NULL){
    printf("error\n");
    exit(1);
  }
  for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }

  int m;
  scanf("%d", &m);

  int *result = NULL;
  int result_size = 0;

  for(int i = 0; i < m; i++){
    int x;
    scanf("%d", &x);
    if(! find_x(x, arr, n)){
      if(! find_x(x, result, result_size)){
        result_size++;
        result = realloc(result, result_size);
        if(result == NULL){
          printf("error\n");
          exit(1);
        }
        result[result_size - 1] = x;
      }
    }else{
      arr = remove_x(x, arr, n--);
    }
  }

  int sorted = 0;
  while(! sorted){
    sorted = 1;
    for(int i = 1; i < result_size; i++){
      if(result[i] < result[i - 1]){
        int tmp = result[i];
        result[i] = result[i - 1];
        result[i - 1] = tmp;
        sorted = 0;
      }
    }
  }

  for(int i = 0; i < result_size - 1; i++){
    printf("%d ", result[i]);
  }
  printf("%d\n", result[result_size - 1]);

  if(arr != NULL){
    free(arr);
  }
  return 0;
}

/* logica em python
n = int(input())
arr = [int(x) for x in input().split()]
m = int(input())
brr = [int(x) for x in input().split()]

result = []

for i in brr:
    if i not in arr:
        if i not in result:
            result.append(i)
    else:
        arr.remove(i)


result.sort()
print(*result)



*/

