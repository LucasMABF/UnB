#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <string>

class Matricula {
 private:
  std::string matricula;
  static bool validar(const std::string &);

 public:
  void setMatricula(const std::string &);
  std::string getMatricula() const;
  Matricula(const std::string &);
};

inline std::string Matricula::getMatricula() const { return this->matricula; }

inline Matricula::Matricula(const std::string &matricula) {
  this->setMatricula(matricula);
}

class Senha {
 private:
  std::string senha;
  static bool validar(const std::string &);

 public:
  void updateSenha(const std::string &senha_anterior,
                   const std::string &nova_senha);
  bool checkSenha(const std::string &) const;
  Senha(const std::string &);
};

inline bool Senha::checkSenha(const std::string &senha) const {
  return this->senha == senha;
}

#endif
