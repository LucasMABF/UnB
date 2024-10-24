// Lista 08 - 1255 - Frequência de Letras
#include <stdio.h>
#include <string.h>

typedef struct letra{
    char letra;
    int freq;
} letra;

int add(char a, letra *lista, int n) {
    if(a  >= 'A' && a <= 'Z'){
        a += 32;
    }else if(a < 'a' || a > 'z'){
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (lista[i].letra == a) {
            lista[i].freq++;
            return 0;
        }
    }
    letra y;
    y.letra = (int) a;
    y.freq = 1;
    lista[n] = y;
    return 1;
}

void sort(letra *lista, int n) {
  int sorted = 0;
  while (!sorted) {
    sorted = 1;
    for (int i = 0; i < n - 1; i++) {
        if (lista[i + 1].freq > lista[i].freq) {
            sorted = 0;
            letra temp = lista[i + 1];
            lista[i + 1] = lista[i];
            lista[i] = temp;
        }else if(lista[i + 1].freq == lista[i].freq && lista[i + 1].letra < lista[i].letra){
            sorted = 0;
            letra temp = lista[i + 1];
            lista[i + 1] = lista[i];
            lista[i] = temp;
        }
    }
  }
}


int main(){
    int n;
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++){
        char linha[200];
        scanf("%[^\n]", linha);
        getchar();
        int len = strlen(linha);
        letra letras[len];
        int len1 = 0;
        for(int j = 0; j < len; j++){
            len1 += add(linha[j], letras, len1);
        }

        sort(letras, len1);


        for(int j = 0; j < len1; j++){
            printf("%c", letras[j].letra);
            if(letras[j + 1].freq != letras[j].freq){
                break;
            }
        }
        printf("\n");
    }

    return 0;
}
