#include <iostream>
#include <stdexcept>
#include "dominios/dominios.hpp"
#include "entidades/entidades.hpp"

using namespace std;

int main() {
  Projeto projeto;
  CodigoCliente codigo;
  Prioridade prioridade;

  try {
    int input;
    cin >> input;
    if(cin.fail()) {
      cin.clear();
      throw invalid_argument("Erro na leitura.");
    }
    codigo.setValor(input);
  } catch (invalid_argument *exp){ // catch pointer because of new
    cout << "Informações inválidas." << endl;
    cout << exp->what() << endl;
    return 1;
  } catch (invalid_argument &exp){ // catch cin fail
    cout << exp.what() << endl;
    return 1;
  }

  try {
    int input;
    cin >> input;
    if(cin.fail()) {
      cin.clear();
      throw invalid_argument("Erro na leitura.");
    }
    prioridade.setValor(input);
  } catch (const invalid_argument &exp){ // catch both
    cout << "Informações inválidas." << endl;
    cout << exp.what() << endl;
    return 1;
  }

  projeto.setCodigo(codigo);
  projeto.setPrioridade(prioridade);

  cout << projeto.getCodigo().getValor() << endl;

  cout << projeto.getPrioridade().getValor() << endl;

  return 0;
}

