// Questionario aula 14
#include <iostream>

using namespace std;

class Elemento {
  private:
    int dado;
  public:
    Elemento *ptr_next;
    void setDado(int dado);
    int getDado();
};

inline void Elemento::setDado(int dado) {
  this->dado = dado;
}

inline int Elemento::getDado() {
  return this->dado;
}

class Fila {
  private:
    Elemento *fim;
    Elemento *inicio;
  public:
    Fila();
    void inserir(Elemento *elemento);
    Elemento *remover();
};


Fila::Fila() { 
  fim = NULL; 
  inicio = NULL;
}

void Fila::inserir(Elemento *elemento) {
  if (!this->inicio) {
    elemento->ptr_next = NULL;
    this->inicio = elemento;
    this->fim = elemento;
    return;
  }

  this->fim->ptr_next = elemento;
  this->fim = elemento;
}

Elemento *Fila::remover() {
  Elemento *primeiro = this->inicio;
  if(!primeiro) return NULL;
  this->inicio = this->inicio->ptr_next;
  if(!this->inicio) this->fim = NULL;
  return primeiro;
}


int main() {
  Elemento elementoA, elementoB, elementoC;
  int dado;

  cin >> dado;
  elementoA.setDado(dado);

  cin >> dado;
  elementoB.setDado(dado);

  cin >> dado;
  elementoC.setDado(dado);

  Fila fila;

  fila.inserir(&elementoA);
  fila.inserir(&elementoB);
  fila.inserir(&elementoC);

  cout << fila.remover()->getDado();
  cout << fila.remover()->getDado();
  cout << fila.remover()->getDado();

  return 0;
}
