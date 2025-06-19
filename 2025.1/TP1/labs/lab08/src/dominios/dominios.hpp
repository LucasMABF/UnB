#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <string>

class Matricula {
 private:
  std::string matricula;
  static bool validar(std::string);

 public:
  void setMatricula(std::string);
  std::string getMatricula() const;
  Matricula(std::string);
};

inline std::string Matricula::getMatricula() const { return this->matricula; }

class Senha {
 private:
  std::string senha;
  static bool validar(std::string);

 public:
  void updateSenha(std::string senha_anterior, std::string nova_senha);
  bool checkSenha(std::string) const;
  Senha(std::string);
};

#endif
