// Script que cria um índice de todos os exercícios para o arquivo README.md
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *output = fopen("README.md", "rb+");
    fseek(output, 97, SEEK_SET);

    int ex = 0;
    int current = -1;
    while(1){
        char nome[14]; // ex000/ex000.c
        snprintf(nome, 14, "ex%03d/ex%03d.c", ex, ex);
        FILE *f = fopen(nome, "rb");
        if(!f){
            break;
        }
        char header[100];
        fgets(header, 100, f);
        int len = strlen(header);
        header[len - 2] = '\0';

        char lista[2] = {header[9], header[10]};
        int l = atoi(lista);
        if (l != current){
            char h[20];
            snprintf(h, 20, "### Lista %d\n\n", l);
            fputs(h, output);
            current = l;
        }

        char linha[200]; // [ex000](ex000/ex000.c): [1001 - Hello World!](https://judge.beecrowd.com/pt/problems/view/1001)
        snprintf(linha, 200, "- [ex%03d](ex%03d/ex%03d.c): [%s](https://judge.beecrowd.com/pt/problems/view/%c%c%c%c)\n\n", ex, ex, ex, &header[14], header[14], header[15], header[16], header[17]);
        fputs(linha, output);
        fclose(f);
        ex++;  
    }

    fclose(output);

    return 0;
}
