// Lista 10 - E - Laptops
#include <stdio.h>
#include <stdlib.h>

typedef struct Laptop{
  int price;
  int quality;
} Laptop;

int compare(const void *a, const void *b){
  return (*(Laptop*)b).quality - (*(Laptop*)a).quality;
}

int main(){
  int n;
  scanf("%d", &n);
  
  Laptop laptops[n];

  for(int i = 0; i < n; i++){
    scanf("%d %d", &laptops[i].price, &laptops[i].quality);
  }

  qsort(laptops, n, sizeof(Laptop), compare);

  int found = 0;
  for(int i = 1; i < n; i++){
    if(laptops[i - 1].price < laptops[i].price){
      found = 1;
    }
  }

  if(found){
    printf("Happy Alex\n");
  }else{
    printf("Poor Alex\n");
  }

  return 0;
}

