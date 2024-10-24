// Lista 08 - 1171 - Frequência de Números
#include <stdio.h>
typedef struct number {
  int n;
  int freq;
} number;

int add(int x, number *ns, int n) {
  for (int i = 0; i < n; i++) {
    if (ns[i].n == x) {
      ns[i].freq++;
      return 0;
    }
  }
  number y;
  y.n = x;
  y.freq = 1;
  ns[n] = y;
  return 1;
}

void sort(number *ns, int n) {
  int sorted = 0;
  while (!sorted) {
    sorted = 1;
    for (int i = 0; i < n - 1; i++) {
      if (ns[i + 1].n < ns[i].n) {
        sorted = 0;
        number temp = ns[i + 1];
        ns[i + 1] = ns[i];
        ns[i] = temp;
      }
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  number numbers[n];
  int len = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);

    len += add(x, numbers, len);
  }

  sort(numbers, len);

  for(int i = 0; i < len; i++){
    printf("%d aparece %d vez(es)\n", numbers[i].n, numbers[i].freq);
    
  }

  return 0;
}
