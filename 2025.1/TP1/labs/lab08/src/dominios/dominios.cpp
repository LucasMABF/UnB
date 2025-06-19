#include "dominios.hpp"

#include <regex>
#include <stdexcept>

bool Matricula::validar(std::string matricula) {
  static const std::regex regex_matricula("^\\d{2}/[12]\\d{6}$");

  return std::regex_match(matricula, regex_matricula);
}

void Matricula::setMatricula(std::string matricula) {
  if (Matricula::validar(matricula)) {
    this->matricula = matricula;
  } else {
    throw std::invalid_argument("Matrícula inválida.");
  }
}

Matricula::Matricula(std::string matricula) { this->setMatricula(matricula); }

bool Senha::validar(std::string senha) {
  static const std::regex regex_senha("^(?=.*\\d)(?=.*[A-Z]).{6,}$");

  return std::regex_match(senha, regex_senha);
}

Senha::Senha(std::string senha) {
  if (Senha::validar(senha)) {
    this->senha = senha;
  } else {
    throw std::invalid_argument(
        "Senha deve ter no mínimo 6 caracteres e deve conter 1 digito e uma "
        "letra maiúscula.");
  }
}

bool Senha::checkSenha(std::string senha) const { return this->senha == senha; }

void Senha::updateSenha(std::string senha_anterior, std::string nova_senha) {
  if (this->checkSenha(senha_anterior)) {
    if (Senha::validar(nova_senha)) {
      this->senha = nova_senha;
    } else {
      throw std::invalid_argument(
          "Senha deve ter no mínimo 6 caracteres e deve conter 1 digito e uma "
          "letra maiúscula.");
    }
  } else {
    throw std::invalid_argument("Senha incorreta.");
  }
}
