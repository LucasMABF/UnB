// Questionario aula 05
#include <iostream>

using namespace std;

class Endereco {
  private:
    string cidade;
    string estado;

  public:    
    Endereco(string);
    Endereco(string, string);
    string getCidade();
    string getEstado();
};

Endereco::Endereco(string cidade){
  this->cidade = cidade;
  this->estado = "DF";
}

Endereco::Endereco(string cidade, string estado){
  this->cidade = cidade;
  this->estado = estado;
}

string Endereco::getCidade() {
  return this->cidade;
}

string Endereco::getEstado() {
  return this->estado;
}

int main(){

  string cidade, estado;

  cin >> cidade;

  cin >> estado;    

  Endereco enderecoA(cidade);

  Endereco enderecoB(cidade, estado);   

  cout << enderecoA.getCidade();

  cout << enderecoB.getCidade();

  cout << enderecoB.getEstado();

  return 0;

}
