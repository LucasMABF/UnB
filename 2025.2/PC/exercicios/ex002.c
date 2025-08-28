// Repetitions
// https://cses.fi/problemset/task/1069
#include <stdio.h>

int main(){
  int longest = 1;
  int current = 1;
  char last = EOF;
  while (1) {
    char c = getchar();
    if (c == last) {
      current += 1;
    } else {
      if (current > longest) {
        longest = current;
      }
      current = 1;
      last = c;
    }
    if (c == '\n' || c == EOF) break;
  }

  printf("%d\n", longest);
  return 0;
}
