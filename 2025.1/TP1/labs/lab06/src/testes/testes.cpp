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

void TUProjeto::testarCenario() {
  CodigoCliente codigo;
  codigo.setValor(TUProjeto::VALOR_VALIDO);
  this->projeto->setCodigo(codigo);
  if(this->projeto->getCodigo().getValor() != TUProjeto::VALOR_VALIDO) {
    this->estado = TUProjeto::FALHA;
  }

  Prioridade prioridade;
  prioridade.setValor(TUProjeto::VALOR_VALIDO);
  this->projeto->setPrioridade(prioridade);
  if(this->projeto->getPrioridade().getValor() != TUProjeto::VALOR_VALIDO) {
    this->estado = TUProjeto::FALHA;
  }

}

int TUProjeto::run() {
  this->setUp();
  this->testarCenario();
  this->tearDown();
  return this->estado;
}

