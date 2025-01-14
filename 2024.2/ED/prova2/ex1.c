#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int codigo;
    char *nome;
} Profissao;

Profissao* aloca_profissao(unsigned int tamanho_nome){
  char *ptr = malloc(tamanho_nome * sizeof(char));
  if(ptr == NULL){
    return NULL;
  }
  Profissao *ptr_prof = malloc(sizeof(Profissao));
  if(ptr_prof == NULL){
    return NULL;
  }
  ptr_prof->nome = ptr;
  return ptr_prof;
}

int main(){
  Profissao *ptr = aloca_profissao(10);
  printf("%lu\n", sizeof(*ptr));
  ptr = aloca_profissao(400);
  printf("%lu\n", sizeof(*ptr));
  
  return 0;
}
