// Lista 08 - 1251 - Diga-me a Frequência
#include <stdio.h>
#include <string.h>
typedef struct letra{
    int ascii;
    int freq;
} letra;

int add(char a, letra *lista, int n) {
  for (int i = 0; i < n; i++) {
    if (lista[i].ascii == a) {
      lista[i].freq++;
      return 0;
    }
  }
  letra y;
  y.ascii = (int) a;
  y.freq = 1;
  lista[n] = y;
  return 1;
}

void sort(letra *lista, int n) {
  int sorted = 0;
  while (!sorted) {
    sorted = 1;
    for (int i = 0; i < n - 1; i++) {
        if (lista[i + 1].freq < lista[i].freq) {
            sorted = 0;
            letra temp = lista[i + 1];
            lista[i + 1] = lista[i];
            lista[i] = temp;
        }else if(lista[i + 1].freq == lista[i].freq && lista[i + 1].ascii > lista[i].ascii){
            sorted = 0;
            letra temp = lista[i + 1];
            lista[i + 1] = lista[i];
            lista[i] = temp;
        }
    }
  }
}


int main(){
    char linha[1000];
    int primeiro = 1;
    while(scanf("%[^\n]", linha) != EOF){
        if(! primeiro){
            printf("\n");
        }
        primeiro = 0;
        getchar();
        int n = strlen(linha);
        letra letras[n];
        int len = 0;
        for(int i = 0; i < n; i++){
            len += add(linha[i], letras, len);
        }

        sort(letras, len);

        for(int i = 0; i < len; i++){
            printf("%d %d\n", letras[i].ascii, letras[i].freq);
        }

    }
    return 0;
}
