// Questionario aula 08
#include <iostream>
#include <stdexcept>
using namespace std;

class Codigo {
  private:
    int valor;
  public:
    void set(int valor);
    int get();
};

inline int Codigo::get() {
  return this->valor;
}

void Codigo::set(int valor) {
  if (valor > 100) {
    throw invalid_argument("Argumento Inválido.");
  }
  this->valor = valor;
}

class Preco {
  private:
    int valor;
  public:
    void set(int valor);
    int get();
};

inline int Preco::get() {
  return this->valor;
}

void Preco::set(int valor) {
  if (valor > 200) {
    throw invalid_argument("Argumento Inválido.");
  }
  this->valor = valor;
}

class Pedido {
  private:
    Codigo codigo;
    Preco preco;
  public:
    void setCodigo(Codigo codigo);
    void setPreco(Preco preco);
    Codigo getCodigo();
    Preco getPreco();
};

Codigo Pedido::getCodigo() {
  return this->codigo;
}
Preco Pedido::getPreco() {
  return this->preco;
}

void Pedido::setCodigo(Codigo codigo) {
  this->codigo = codigo;
}

void Pedido::setPreco(Preco preco) {
  this->preco = preco;
}


int main(){  
  int dadoA, dadoB;
  cin >> dadoA;
  cin >> dadoB;
  Codigo codigo;
  Preco preco;

  try{
    codigo.set(dadoA);
    preco.set(dadoB);
  } catch(invalid_argument &excecao){
    cout << "FALHA";
    return 0;
  }

  Pedido pedido;

  pedido.setCodigo(codigo);
  pedido.setPreco(preco);

  cout << pedido.getCodigo().get();
  cout << pedido.getPreco().get();

  return 0;
}

