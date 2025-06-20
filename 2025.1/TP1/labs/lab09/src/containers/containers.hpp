#ifndef CONTAINERS_HPP_INCLUDED
#define CONTAINERS_HPP_INCLUDED

#include <list>

#include "dominios/dominios.hpp"
#include "entidades/entidades.hpp"

class ContainerUsuario {
 private:
  std::list<Usuario> container;

 public:
  bool incluir(const Usuario&);
  bool remover(const Matricula&);
  bool pesquisar(Usuario&) const;
  bool atualizar(const Usuario&);
};

#endif
