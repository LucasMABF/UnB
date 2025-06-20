#include "containers.hpp"

#include <cassert>

#include "dominios/dominios.hpp"
#include "entidades/entidades.hpp"

bool ContainerUsuario::incluir(const Usuario &usuario) {
  for (auto &elemento : this->container) {
    if (elemento.getMatricula()->getMatricula() ==
        usuario.getMatricula()->getMatricula()) {
      return false;
    }
  }
  this->container.push_back(
      Usuario(*usuario.getMatricula(), *usuario.getSenha()));
  return true;
}

bool ContainerUsuario::remover(const Matricula &matricula) {
  for (auto elemento = container.begin(); elemento != container.end();
       elemento++) {
    if (elemento->getMatricula()->getMatricula() == matricula.getMatricula()) {
      container.erase(elemento);
      return true;
    }
  }
  return false;
}

bool ContainerUsuario::pesquisar(Usuario &usuario) const {
  for (auto &elemento : this->container) {
    if (elemento.getMatricula()->getMatricula() ==
        usuario.getMatricula()->getMatricula()) {
      usuario = Usuario(*elemento.getMatricula(), *elemento.getSenha());
      return true;
    }
  }
  return false;
}

bool ContainerUsuario::atualizar(const Usuario &usuario) {
  for (auto &elemento : this->container) {
    if (elemento.getMatricula()->getMatricula() ==
        usuario.getMatricula()->getMatricula()) {
      elemento = Usuario(*usuario.getMatricula(), *usuario.getSenha());
      return true;
    }
  }
  return false;
}
