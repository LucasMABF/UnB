#ifndef INTERFACES_HPP_INCLUDED
#define INTERFACES_HPP_INCLUDED

#include "dominios/dominios.hpp"

class ILNAutenticacao {
 public:
  virtual void autenticar(const Matricula &, const Senha &) = 0;
  virtual ~ILNAutenticacao() = default;
};

class IUAutenticacao {
 protected:
  ILNAutenticacao *cntrLNAutenticacao;

 public:
  virtual Matricula *autenticar() = 0;
  void setCntrLNAutenticacao(ILNAutenticacao *);
  virtual ~IUAutenticacao() = default;
};

void inline IUAutenticacao::setCntrLNAutenticacao(ILNAutenticacao *ctr) {
  this->cntrLNAutenticacao = ctr;
};

#endif
