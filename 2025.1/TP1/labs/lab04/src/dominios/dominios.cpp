#include "dominios.hpp"
#include <stdexcept>

void Dominio::setValor(int valor) {
  this->validar(valor);
  this->valor = valor;
}

void CodigoCliente::validar(int valor) const {
  if(valor > CodigoCliente::LIMITE) {
    throw new std::invalid_argument("Argumento Inválido.");
  }
}

void Prioridade::validar(int valor) const{
  if (valor == this->INVALIDO) {
    throw std::invalid_argument("Argumento Inválido.");
  }

}
