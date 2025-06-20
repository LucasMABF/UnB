#ifndef ENTIDADES_HPP_INCLUDED
#define ENTIDADES_HPP_INCLUDED

#include <memory>

#include "dominios/dominios.hpp"

class Usuario {
 private:
  std::unique_ptr<Matricula> matricula;
  std::unique_ptr<Senha> senha;

 public:
  Matricula *getMatricula() const;
  Senha *getSenha() const;
  void setMatricula(std::unique_ptr<Matricula>);
  void setMatricula(const Matricula &);
  void setSenha(std::unique_ptr<Senha>);
  void setSenha(const Senha &);
  Usuario(const Matricula &matricula, const Senha &senha)
      : matricula(std::make_unique<Matricula>(matricula)),
        senha(std::make_unique<Senha>(senha)) {}
  Usuario() = default;
};

inline Matricula *Usuario::getMatricula() const {
  return this->matricula.get();
}

inline Senha *Usuario::getSenha() const { return this->senha.get(); }

inline void Usuario::setMatricula(const Matricula &matricula) {
  this->matricula = std::make_unique<Matricula>(matricula);
}

inline void Usuario::setSenha(const Senha &senha) {
  this->senha = std::make_unique<Senha>(senha);
}

#endif
