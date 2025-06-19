#include "fabricas.hpp"

Dominio *FabricaDominio1::instanciarDominioA() const {
  return new DominioA1();
}

Dominio *FabricaDominio1::instanciarDominioB() const {
  return new DominioB1();
}

Dominio *FabricaDominio2::instanciarDominioA() const {
  return new DominioA2();
}

Dominio *FabricaDominio2::instanciarDominioB() const {
  return new DominioB2();
}
