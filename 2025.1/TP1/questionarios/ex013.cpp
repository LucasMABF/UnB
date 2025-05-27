#include <iostream>
using namespace std;

class Elemento {
 private:
  int chave;
  Elemento *proximo;

 public:
  int getChave() const;
  Elemento *getProximo() const;
  void setProximo(Elemento *);
  Elemento(int);
};

Elemento::Elemento(int value) {
  this->chave = value;
  this->proximo = nullptr;
}

inline int Elemento::getChave() const { return this->chave; }

inline Elemento *Elemento::getProximo() const { return this->proximo; }

inline void Elemento::setProximo(Elemento *prox) { this->proximo = prox; }

class TabelaDispersao {
 private:
  int dimensao;
  Elemento **entrada;
  int funcaoDispersao(int);

 public:
  TabelaDispersao(int);
  ~TabelaDispersao() { delete[] entrada; }
  Elemento *ler(int);
  void inserir(Elemento *);
  void remover(int);
};

inline int TabelaDispersao::funcaoDispersao(int valor) {
  return valor % dimensao;
}

TabelaDispersao::TabelaDispersao(int dimensao) {
  entrada = new Elemento *[dimensao];

  for (int n = 0; n < dimensao; n++) entrada[n] = nullptr;

  this->dimensao = dimensao;
}

Elemento *TabelaDispersao::ler(int chave) {
  Elemento *ponteiro = entrada[funcaoDispersao(chave)];

  while (ponteiro != nullptr) {
    if (ponteiro->getChave() == chave) return ponteiro;

    ponteiro = ponteiro->getProximo();
  }

  return nullptr;
}

void TabelaDispersao::inserir(Elemento *elemento) {
  Elemento *ponteiro = entrada[funcaoDispersao(elemento->getChave())];

  Elemento *anterior;

  if (ponteiro == nullptr) {
    entrada[funcaoDispersao(elemento->getChave())] = elemento;

  }

  else {
    while (ponteiro != nullptr) {
      if (ponteiro->getChave() == elemento->getChave()) return;

      anterior = ponteiro;

      ponteiro = ponteiro->getProximo();
    }

    anterior->setProximo(elemento);
  }
}

void TabelaDispersao::remover(int chave) {
  Elemento *ponteiro = entrada[funcaoDispersao(chave)];

  Elemento *anterior;

  if (ponteiro->getChave() == chave) {
    entrada[funcaoDispersao(chave)] = ponteiro->getProximo();

  }

  else {
    while (ponteiro->getProximo() != nullptr) {
      anterior = ponteiro;

      ponteiro = ponteiro->getProximo();

      if (ponteiro->getChave() == chave) {
        anterior->setProximo(ponteiro->getProximo());

        break;
      }
    }
  }

  return;
}

int main() {
  TabelaDispersao tabela(2);
  Elemento *ponteiro;
  int entrada;

  tabela.inserir(new Elemento(100));
  tabela.inserir(new Elemento(200));
  tabela.inserir(new Elemento(300));
  tabela.inserir(new Elemento(401));
  tabela.inserir(new Elemento(501));
  tabela.remover(200);

  for (int n = 1; n < 6; n++) {
    cin >> entrada;
    ponteiro = tabela.ler(entrada);

    if (ponteiro == nullptr)
      cout << 0;
    else
      cout << ponteiro->getChave();
  }

  return 0;
}
