#include "controladoras.hpp"

#include <iostream>
#include <stdexcept>
#include <string>

#include "dominios/dominios.hpp"

Matricula *CntrIUAutenticacao::autenticar() {
  Matricula *matricula = nullptr;
  Senha *senha = nullptr;

  while (true) {
    std::cout << std::endl
              << "Autenticação de usuário" << std::endl
              << std::endl;
    try {
      std::string matricula_str;
      std::string senha_str;

      std::cout << "Digite a matrícula: ";
      std::cin >> matricula_str;
      matricula = new Matricula(matricula_str);

      std::cout << "Digite a senha: ";
      std::cin >> senha_str;
      senha = new Senha(senha_str);
      break;

    } catch (const std::invalid_argument &e) {
      std::cout << std::endl << "Dado inválido: " << e.what() << std::endl;
      delete matricula;
      matricula = nullptr;
    }
  }

  try {
    this->cntrLNAutenticacao->autenticar(*matricula, *senha);
  } catch (...) {
    delete matricula;
    delete senha;
    throw;
  }
  delete senha;  // already handled, preventing leak

  return matricula;
}
