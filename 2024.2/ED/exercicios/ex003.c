// Lista 1 - D - apple-and-orange
#include <stdio.h>

int main(){
  int s, t, a, b, m, n;
  scanf("%d %d %d %d %d %d", &s, &t, &a, &b, &m, &n);

  int apples = 0;
  for(int i = 0; i < m; i++){
    int x;
    scanf("%d", &x);
    if(a + x >= s && a + x <= t) apples++;
  }
  
  int oranges = 0;
  for(int i = 0; i < n; i++){
    int x;
    scanf("%d", &x);
    if(b + x >= s && b + x <= t) oranges++;
  }
  
  printf("%d\n%d\n", apples, oranges);

  return 0;
}

