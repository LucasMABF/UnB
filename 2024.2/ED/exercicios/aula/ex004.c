// aula recursao
// fibonacci 
#include <stdio.h>
#include <stdlib.h>

long long int* cache = NULL;
int size_cache = 0;

long long int fibonacci(int n){
  if(size_cache <= n){
    cache = realloc(cache, (n + 1) * sizeof(long long int));
    if(cache == NULL){
      printf("error");
      exit(1);
    }
    for(int i = size_cache; i < n + 1; i++){
      cache[i] = -1;
    }
    size_cache = n + 1;
  }
  else if(cache[n] > 0){
    return cache[n];
  }

  if(n == 0){
    cache[0] = 1;
    return 1;
  }
  if (n == 1) {
    cache[1] = 1;
    return 1;
  }

  long long int result = fibonacci(n - 1) + fibonacci(n - 2);
  cache[n] = result;
  return result;
}

int main(){
  int n;
  scanf("%d", &n);
  
  for(int i = 0; i <= n; i++){
    long long int resultado = fibonacci(i);
    printf("%d = %lld\n", i, resultado);
  }

  return 0;
}

