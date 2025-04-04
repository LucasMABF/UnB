// Lista 5 - A - The Coco-Cola Store
#include <stdio.h>

long int calcular_garrafas(int n){
  if(n == 2){
    n++;
  }
  int novas_cheias = n / 3;
  if(novas_cheias == 0){
    return 0;
  }
  
  return novas_cheias + calcular_garrafas(novas_cheias + n % 3);
}

int main(){
  int n;
  while(1){
    scanf("%d", &n);
    if(n == 0){
      break;
    }

    int resultado = calcular_garrafas(n);

    printf("%d\n", resultado);

  }

  return 0;
}

