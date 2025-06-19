#include "stubs/stubs.hpp"

#include <iostream>
#include <stdexcept>

#include "dominios/dominios.hpp"

const char StubLNAutenticacao::PAS;
const char StubLNAutenticacao::VEST;

void StubLNAutenticacao::autenticar(const Matricula &matricula,
                                    const Senha &senha) {
  std::cout << std::endl << "StubLNAutenticacao::autenticar" << std::endl;
  std::cout << "Mátricula: " << matricula.getMatricula() << std::endl;

  switch (matricula.getMatricula()[3]) {
    case StubLNAutenticacao::PAS:
      std::cout << "Método de ingresso: PAS" << std::endl;
      break;
    case StubLNAutenticacao::VEST:
      std::cout << "Método de ingresso: VEST" << std::endl;
      throw std::runtime_error(
          "Erro de sistema: método de ingresso VEST não suportado pelo "
          "sistema.");
  }
}
