// Lista 06 - 1049 - Animal
#include <stdio.h>
#include <string.h>

int main(){
    char a[12];
    scanf("%s", a);

    char b[9];
    scanf("%s", b);

    char c[11];
    scanf("%s", c);

    if(strcmp(a, "vertebrado") == 0){
        if(strcmp(b, "ave") == 0){
            if(strcmp(c, "carnivoro") == 0){
                printf("aguia\n");
            }else{
                printf("pomba\n");
            }
        }else{
            if(strcmp(c, "onivoro") == 0){
                printf("homem\n");
            }else{
                printf("vaca\n");
            }
        }
    }else{
        if(strcmp(b, "inseto") == 0){
            if(strcmp(c, "hematofago") == 0){
                printf("pulga\n");
            }else{
                printf("lagarta\n");
            }
        }else{
            if(strcmp(c, "hematofago") == 0){
                printf("sanguessuga\n");
            }else{
                printf("minhoca\n");
            }
        }
    }

    return 0;
}
