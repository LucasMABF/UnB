#include <iostream>
#include "dominios/dominios.hpp"
#include "entidades/entidades.hpp"

using namespace std;

int main() {
  Projeto projeto;
  CodigoCliente codigo;
  Prioridade prioridade;

  bool error = false;
  error = error || !codigo.setValor(10);
  error = error || !prioridade.setValor(20);

  if(error) {
    cout << "Informações inválidas." << endl;
    return 1;
  }

  projeto.setCodigo(codigo);
  projeto.setPrioridade(prioridade);

  cout << projeto.getCodigo().getValor() << endl;

  cout << projeto.getPrioridade().getValor() << endl;

  return 0;
}

