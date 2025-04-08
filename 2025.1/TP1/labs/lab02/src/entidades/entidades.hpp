#ifndef ENTIDADES_HPP_INCLUDED
#define ENTIDADES_HPP_INCLUDED

#include "../dominios/dominios.hpp"

class Projeto {
  private:
    CodigoCliente codigo;
    Prioridade prioridade;
  public:
    void setCodigo(CodigoCliente);
    CodigoCliente getCodigo();
    void setPrioridade(Prioridade);
    Prioridade getPrioridade();
};

inline void Projeto::setCodigo(CodigoCliente codigo) {
  this->codigo = codigo;
}

inline CodigoCliente Projeto::getCodigo() {
  return this->codigo;
}

inline void Projeto::setPrioridade(Prioridade prioridade) {
  this->prioridade = prioridade;
}

inline Prioridade Projeto::getPrioridade() {
  return this->prioridade;
}

#endif
