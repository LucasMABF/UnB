#include "dominios.hpp"

bool Dominio::setValor(int valor) {
  if (!this->validar(valor)) {
    return false;
  }
  this->valor = valor;
  return true;
}

bool DominioA1::validar(int valor) {
  if (valor != 42) {
    return false;
  }
  return true;
}

bool DominioA2::validar(int valor) {
  if (valor == 42) {
    return false;
  }
  return true;
}

bool DominioB1::validar(int valor) {
  if (valor != 73) {
    return false;
  }
  return true;
}

bool DominioB2::validar(int valor) {
  if (valor == 73) {
    return false;
  }
  return true;
}
