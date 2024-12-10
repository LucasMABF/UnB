// Exercício de Revisão
#include <math.h>
#include <stdio.h>

int main(){
  int size;
  scanf("%d", &size);
  printf("Data size of %d bytes:\n", size);

  int current;
  int c = 0;
  int sum = 0;
  while(scanf("%d",  &current)){
    c++;
    sum += current;
    size -= current;

    if(c % 5 == 0){
      if(sum == 0){
        printf("Time remaining: stalled\n");
      }else{
        printf("Time remaining: %d seconds\n", (int) ceil(size / (sum / 5.0)));
      }
      sum = 0;
    }
  }

  printf("Total time: %d seconds\n", c);
  
  return 0;
}

