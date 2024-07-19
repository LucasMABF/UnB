#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    FILE *output = fopen("README.md", "wb");

    char header[] = "# Provas de APC\n\n- Resoluções dos exercícios das provas de APC.\n\n### Index\n";
    fputs(header, output);

    int prova = 0;
    int br = 0;
    while(1){
        int ex = 1;
        int new = 1;
        while(1){
            char nome[20]; // prova0/ex00/ex00.c
            snprintf(nome, 20, "prova%d/ex%d/ex%d.c", prova, ex, ex);
            FILE *f = fopen(nome, "rb");
            if(!f){
                if(ex == 1){
                    br = 1;
                }
                break;
            }
            char header[100];
            fgets(header, 100, f);
            int len = strlen(header);
            if(header[len - 2] == 13){ // carriage return
                header[len - 2] = '\0';
            }else{
                header[len - 1] = '\0';
            }


            if(new){
                char h[26];
                if(prova == 0){
                    snprintf(h, 26, "\n### Prova %d (Anulada)\n", prova);
                }else{
                    snprintf(h, 26, "\n### Prova %d\n", prova);
                }
                fputs(h, output);
            }
            new = 0;

            char linha[200]; // [ex000](ex000/ex000.c): [1001 - Hello World!](https://judge.beecrowd.com/pt/problems/view/1001)
            char lista1[] = {header[3], header[4], header[5], header[6], '\0'};
            snprintf(linha, 200, "\n- [ex%d](prova%d/ex%d/ex%d.c): [%s](https://judge.beecrowd.com/pt/problems/view/%c%c%c%c)\n", ex, prova, ex, ex, &header[3], header[3], header[4], header[5], header[6]);

            fputs(linha, output);
            fclose(f);
            ex++;
        }
        if(br){
            break;
        }
        prova++;
    }

    fclose(output);

    return 0;
}
