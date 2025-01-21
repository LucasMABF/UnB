// aula recursao
// Torre de Hanoi
#include <stdio.h>

void move_tower(int n, int orig, int dest, int tmp){
  if(n == 0) return;
  if(n == 1){
    printf("%c -> %c\n", orig + 'A', dest + 'A');
    return;
  }

  move_tower(n - 1, orig, tmp, dest);
  move_tower(1, orig, dest, tmp);
  move_tower(n - 1, tmp, dest, orig);

}

int main(){
  int n;
  scanf("%d", &n);
  move_tower(n, 0, 2, 1);

  return 0;
}
