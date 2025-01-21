// Aula ordenacao
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
  return *(int*)a < *(int*)b;

}

int main(){
  int n;
  scanf("%d", &n);

  int pilotos[n];
  for(int i = 0; i < n; i++){
    scanf("%d", &pilotos[i]);
  }

  qsort(pilotos, n, sizeof(int), compare);

  int menor = pilotos[0] - pilotos[1];
  int piloto = 0;
  for(int i = 2; i < n; i++){
    if(pilotos[i - 1] - pilotos[i] < menor){
      menor = pilotos[i - 1] - pilotos[i];
      piloto = i - 1;

    }
  }

  printf("%d: piloto %d e piloto %d.\n", menor, pilotos[piloto], pilotos[piloto+1]);

  return 0;
}

