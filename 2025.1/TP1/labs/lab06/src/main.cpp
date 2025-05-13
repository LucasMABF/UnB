#include <iostream>
#include "testes/testes.hpp"

using namespace std;

int main() {
  TUProjeto testeEntidade;

  switch(testeEntidade.run()) {
    case TUDominio::SUCESSO:
      cout << "SUCESSO" << endl;
      break;
    case TUDominio::FALHA:
      cout << "FALHA" << endl;
      break;
  }

  return 0;
}

