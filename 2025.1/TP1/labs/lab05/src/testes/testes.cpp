#include <stdexcept>
#include "testes.hpp"

void StubDominio::validar(int teste) const {
  if(teste == 0) {
    throw std::invalid_argument("Argumento Inválido.");
  }
}

void TUDominio::testarCenarioValido() {
  try {
    this->dominio->setValor(TUDominio::VALOR_VALIDO);
    if(this->dominio->getValor() != TUDominio::VALOR_VALIDO) {
      this->estado = TUDominio::FALHA;
    }
  } catch(std::invalid_argument &e) {
    this->estado = TUDominio::FALHA;
  }
}

void TUDominio::testarCenarioInvalido() {
  try {
    this->dominio->setValor(TUDominio::VALOR_INVALIDO);
    this->estado = TUDominio::FALHA;
  } catch(std::invalid_argument &e) {
    if(this->dominio->getValor() == TUDominio::VALOR_INVALIDO) {
      this->estado = TUDominio::FALHA;
    }
  }
}

int TUDominio::run() {
  this->setUp();
  this->testarCenarioValido();
  this->testarCenarioInvalido();
  this->tearDown();
  return this->estado;
}

