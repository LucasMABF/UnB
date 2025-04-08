#include "dominios.hpp"

bool CodigoCliente::validar(int valor) {
  if(valor > LIMITE) {
    return false;
  }
  return true;
}

bool CodigoCliente::setValor(int valor) {
  if(!validar(valor)) {
    return false;
  }
  this->valor = valor;
  return true;
}

bool Prioridade::validar(int valor) {
  if (valor == this->INVALIDO) { return false;
  }

  return true;
}

bool Prioridade::setValor(int valor) {
  if (!Prioridade::validar(valor)) {
    return false;
  }

  this->valor = valor;
  return true;
}
