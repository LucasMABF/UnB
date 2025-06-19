#ifndef CONTROLADORAS_HPP_INCLUDED
#define CONTROLADORAS_HPP_INCLUDED

#include "dominios/dominios.hpp"
#include "interfaces/interfaces.hpp"

class CntrIUAutenticacao : public IUAutenticacao {
 public:
  Matricula* autenticar();
};

#endif
