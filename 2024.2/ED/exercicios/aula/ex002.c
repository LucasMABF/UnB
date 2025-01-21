// aula recursao
#include <stdio.h>


char change_base(int n){
  if(n < 10){
    return n + '0';
  }

  return (n - 10) + 'A';
}

int change_radix(int n, int radix, char *buffer, int size){
  int x = n / radix;
  if(x == 0){
    buffer[0] = change_base(n % radix);
    buffer[1] = '\0';
    return 1;
  }
  
  int index = change_radix(x, radix, buffer, size);
  if(index > size - 1){
    return 0;
  }
  buffer[index] = change_base(n % radix);
  buffer[index + 1] = '\0';
  return index + 1;
  
}


int main(){
  int n, radix;
  scanf("%d %d", &n, &radix);
  char s[100];
  int x = change_radix(n, radix, s, 100);

  printf("%s\n", s);
  printf("%d\n", x);

  return 0;
}

