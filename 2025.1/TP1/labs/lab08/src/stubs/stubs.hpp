#ifndef STUBS_HPP_INCLUDED
#define STUBS_HPP_INCLUDED

#include "dominios/dominios.hpp"
#include "interfaces/interfaces.hpp"

class StubLNAutenticacao : public ILNAutenticacao {
 private:
  const static char PAS = '1';
  const static char VEST = '2';

 public:
  void autenticar(const Matricula&, const Senha&);
};

#endif
