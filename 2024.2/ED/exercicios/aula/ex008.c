// Aula arvore
#include <stdio.h>
#include <stdlib.h>

typedef struct No{
  int value;
  struct No *dir;
  struct No *esq;
} No;

No *newTree(){
  return NULL;
}

No *insertTree(int value, No *raiz){
  if(raiz == NULL){
    No *novo = malloc(sizeof(No));
    if(novo == NULL) exit(1);
    novo->dir = NULL;
    novo->esq = NULL;
    novo->value = value;
    return novo;
  }

  if(value > raiz->value){
    raiz->dir = insertTree(value, raiz->dir);
  }

  if(value < raiz->value){
    raiz ->esq = insertTree(value, raiz->esq);
  }

  return raiz;
}

void printTree(No *raiz){
  if(raiz == NULL) return;

  printTree(raiz->esq);
  printf("%d ", raiz->value);
  printTree(raiz->dir);
}

int main(){
  No *raiz = newTree();
  raiz = insertTree(50, raiz);
  raiz = insertTree(10, raiz);
  raiz = insertTree(25, raiz);
  raiz = insertTree(30, raiz);
  raiz = insertTree(45, raiz);
  raiz = insertTree(5, raiz);
  raiz = insertTree(99, raiz);

  printTree(raiz);
  printf("\n");

  return 0;
}

