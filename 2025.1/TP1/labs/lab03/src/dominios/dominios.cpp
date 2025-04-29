#include "dominios.hpp"

bool Dominio::setValor(int valor) {
  if(!this->validar(valor)) {
    return false;
  }
  this->valor = valor;
  return true;
}

bool CodigoCliente::validar(int valor) const {
  if(valor > CodigoCliente::LIMITE) {
    return false;
  }
  return true;
}

bool Prioridade::validar(int valor) const{
  if (valor == this->INVALIDO) { return false;
  }

  return true;
}
