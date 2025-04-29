// Questionario aula 08
#include <iostream>

using namespace std;

class Codigo {
  private:
    int valor;
  public:
    const static int LIMITE = 100;
    int getValor();
    void setValor(int valor);
};

inline int Codigo::getValor(){
  return valor;
}

void Codigo::setValor(int valor){
  if (valor > LIMITE) {
    throw invalid_argument("Argumento invalido.");
  }
  this->valor = valor;
}


class TUCodigo {
  public:
    bool run (int valor);
};

bool TUCodigo::run(int valor){
  Codigo codigo;
  bool estado = true;

  if(valor <= Codigo::LIMITE) {
    try{
      codigo.setValor(valor);
      if (codigo.getValor() != valor) {
        estado = false;
      }
    }catch(invalid_argument &excecao){
      estado = false;
    }
  }else {
    try{
      codigo.setValor(valor);
      estado = false;
    }catch(invalid_argument &excecao){
      if (codigo.getValor() == valor) {
        estado = false;
      }
    }
  }

  return estado;
}


int main(){
  TUCodigo teste;
  int dado;

  cin >> dado;

  switch(teste.run(dado)){
    case true : cout << "SUCESSO" << endl;
      break;
    case false: cout << "FALHA" << endl;
      break;
  }  

  return 0;
}

