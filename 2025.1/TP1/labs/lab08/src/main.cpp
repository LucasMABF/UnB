#include <iostream>
#include <stdexcept>

#include "controladoras/controladoras.hpp"
#include "dominios/dominios.hpp"
#include "interfaces/interfaces.hpp"
#include "stubs/stubs.hpp"

using namespace std;
int main() {
  IUAutenticacao *cntrIUAutenticacao = new CntrIUAutenticacao();
  ILNAutenticacao *stubLNAutenticacao = new StubLNAutenticacao();

  cntrIUAutenticacao->setCntrLNAutenticacao(stubLNAutenticacao);

  Matricula *matricula = nullptr;

  cout << endl << "Tela inicial de sistema" << endl;
  try {
    matricula = cntrIUAutenticacao->autenticar();
    cout << endl << "Autenticado com sucesso" << endl;
    cout << endl << "Matricula: " << matricula->getMatricula() << endl;
  } catch (const runtime_error &e) {
    cout << "Erro de sistema: " << e.what() << endl;
  }

  delete matricula;
  delete cntrIUAutenticacao;
  delete stubLNAutenticacao;

  return 0;
}
