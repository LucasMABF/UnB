// Questionario aula 05
#include <iostream>

using namespace std;

class Estudante {
  private:
    static int contador;
    string nome;

  public:    
    Estudante(string);
    static int getContador();
    string getNome();
};

int Estudante::contador = 0;

Estudante::Estudante(string nome) {
  this->nome = nome;
  contador++;
}

string Estudante::getNome() {
  return this->nome;
}

int Estudante::getContador() {
  return Estudante::contador;
}


int main(){

  string nomeA, nomeB;   

  cin >> nomeA;

  cin >> nomeB;

  cout << Estudante::getContador();

  Estudante estudanteA(nomeA);

  cout << Estudante::getContador();

  cout << estudanteA.getNome();  

  Estudante estudanteB(nomeB);    

  cout << Estudante::getContador();

  cout << estudanteB.getNome();  

  return 0;

}
