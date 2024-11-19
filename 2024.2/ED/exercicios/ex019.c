// Lista 4 - E - Helpful Maths
#include <stdio.h>

int main(){

  int ones = 0;
  int twos = 0;
  int threes = 0;
  char c;
  do{
    c = getchar();
    if(c == '1'){
      ones++;
    }else if(c == '2'){
      twos++;
    }else if(c == '3'){
      threes++;
    }

  }while(c != '\n');

  for(int i = 0; i < ones; i++){
    if(i != 0){
      printf("+");
    }
    printf("1");
  }

  for(int i = 0; i < twos; i++){
    if(i != 0){
      printf("+");
    }else{
      if(ones > 0) printf("+");
    }
    printf("2");
  }


  for(int i = 0; i < threes; i++){
    if(i != 0){
      printf("+");
    }else{
      if(ones > 0 || twos > 0) printf("+");
    }
    printf("3");
  }

  printf("\n");

  return 0;
}

