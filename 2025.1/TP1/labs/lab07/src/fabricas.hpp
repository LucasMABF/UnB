#ifndef FABRICAS_HPP_INCLUDED
#define FABRICAS_HPP_INCLUDED

#include "dominios.hpp"

class FabricaDominio {
 public:
  virtual Dominio *instanciarDominioA() const = 0;
  virtual Dominio *instanciarDominioB() const = 0;
};

class FabricaDominio1 : public FabricaDominio {
 public:
  Dominio *instanciarDominioA() const;
  Dominio *instanciarDominioB() const;
};

class FabricaDominio2 : public FabricaDominio {
 public:
  Dominio *instanciarDominioA() const;
  Dominio *instanciarDominioB() const;
};

#endif
