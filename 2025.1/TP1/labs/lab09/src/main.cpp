#include <iostream>

#include "containers/containers.hpp"
#include "dominios/dominios.hpp"

using namespace std;

int main() {
  ContainerUsuario container;

  Usuario usuario_1;
  usuario_1.setMatricula(Matricula("25/1345382"));
  usuario_1.setSenha(Senha("Abcd3f"));

  bool resultado = container.incluir(usuario_1);

  if (!resultado) {
    cout << "Erro na inclusão" << endl;
  } else {
    cout << "Sucesso na inclusão" << endl;
  }

  usuario_1.setSenha(Senha("Aaa3333"));

  resultado = container.atualizar(usuario_1);

  if (!resultado) {
    cout << "Erro na atualização" << endl;
  } else {
    cout << "Sucesso na atualização" << endl;
  }

  Usuario usuario_2;
  usuario_2.setMatricula(Matricula("25/1345382"));

  resultado = container.pesquisar(usuario_2);

  if (!resultado) {
    cout << "Erro na pesquisa" << endl;
  } else {
    cout << "Sucesso na pesquisa" << endl;
    cout << usuario_2.getSenha()->checkSenha("Aaa3333") << endl;
  }

  resultado = container.remover(Matricula("25/1345382"));

  if (!resultado) {
    cout << "Erro na remoção" << endl;
  } else {
    cout << "Sucesso na remoção" << endl;
  }

  resultado = container.pesquisar(usuario_2);

  if (!resultado) {
    cout << "Erro na pesquisa" << endl;
  } else {
    cout << "Sucesso na pesquisa" << endl;
  }

  return 0;
}
