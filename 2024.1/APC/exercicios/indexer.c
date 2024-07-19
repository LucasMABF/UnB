// Script que cria um índice de todos os exercícios para o arquivo README.md
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    FILE *output = fopen("README.md", "wb");

    char header[] = "# Exercícios e Provas APC\n\n- Resoluções dos exercícios das listas passadas nas aulas de APC, do beecrowd e dos PDF passados em sala.\n\n### Index\n";
    fputs(header, output);

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
        if(header[len - 2] == 13){ // carriage return
            header[len - 2] = '\0';
        }else{
            header[len - 1] = '\0';
        }

        char lista[3] = {header[9], header[10], '\0'};
        int l = atoi(lista);
        if (l != current){
            char h[20];
            snprintf(h, 20, "\n### Lista %d\n", l);
            fputs(h, output);
            current = l;
        }

        char linha[200]; // [ex000](ex000/ex000.c): [1001 - Hello World!](https://judge.beecrowd.com/pt/problems/view/1001)
        char lista1[] = {header[14], header[15], header[16], header[17], '\0'};
        int digit = 1;
        for(int i = 0; i < 4; i++){
            if(! isdigit(lista1[i])){
                digit = 0;
            }
        }
        int num_ex = atoi(lista1);
        if(digit){
            snprintf(linha, 200, "\n- [ex%03d](ex%03d/ex%03d.c): [%s](https://judge.beecrowd.com/pt/problems/view/%c%c%c%c)\n", ex, ex, ex, &header[14], header[14], header[15], header[16], header[17]);
        }else{
            if(ex == 63 || ex == 64 || ex == 65){
                snprintf(linha, 200, "\n- [ex%03d](ex%03d/ex%03d.c): [%c](ex036/funcoes_ponteiros.pdf)\n", ex, ex, ex, header[14]);
            }else{
                snprintf(linha, 200, "\n- [ex%03d](ex%03d/ex%03d.c): [%c](ex%03d/%c.pdf)\n", ex, ex, ex, header[14], ex, header[14]);
            }
        }

        fputs(linha, output);
        fclose(f);
        ex++;
    }

    fclose(output);

    return 0;
}
