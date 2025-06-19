#include <iostream>

#include "dominios/dominios.hpp"
#include "fabricas/fabricas.hpp"

using namespace std;

int main() {
  FabricaDominio *fabrica;
  Dominio *dominio_a;
  Dominio *dominio_b;

  int opcao;
  cin >> opcao;
  if (opcao == 1) {
    fabrica = new FabricaDominio1();
  } else {
    fabrica = new FabricaDominio2();
  }

  dominio_a = fabrica->instanciarDominioA();
  dominio_b = fabrica->instanciarDominioB();

  bool result = dominio_a->setValor(42);
  result = result && dominio_b->setValor(73);
  if (!result) {
    cout << "Erro ao setar valor. Valor inválido." << endl;
  } else {
    cout << "A = " << dominio_a->getValor() << endl;
    cout << "B = " << dominio_b->getValor() << endl;
  }

  delete dominio_a;
  delete dominio_b;
  delete fabrica;
  return 0;
}
