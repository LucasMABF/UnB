#include <iostream>
#include "dominios.hpp"

using std::cout, std::endl;

int main() {
  CodigoCliente a;

  if (a.setValor(3)) {
    cout << "Valor = " << a.getValor() << endl;
  } else {
    cout << "Valor inválido" << endl;
  }

  if (a.setValor(30)) {
    cout << "Valor = " << a.getValor() << endl;
  } else {
    cout << "Valor inválido" << endl;
  }

  CodigoCliente *ptr;

  ptr = new CodigoCliente();
  
  if (ptr->setValor(5)){
    cout << "Valor = " << ptr->getValor() << endl;
  } else{
    cout << "Valor inválido" << endl;
  }

  if (ptr->setValor(50)) {
    cout << "Valor = " << ptr->getValor() << endl;
  } else{
    cout << "Valor inválido" << endl;
  }

  return 0;
}

