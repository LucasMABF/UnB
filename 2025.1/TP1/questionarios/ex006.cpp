// Questionario aula 07
#include <iostream>

using namespace std;

class Poligono {
  private:
    int n_lados;
  public:
    int getNumeroLados() const;
    virtual float calcularArea() const = 0;
    Poligono(int n_lados): n_lados(n_lados) {}
  
};

inline int Poligono::getNumeroLados() const {
  return this->n_lados;
}

class Quadrado:public Poligono {
  private:
    float lado;
  public:
    Quadrado(float lado): Poligono(4), lado(lado) {};
    virtual float calcularArea() const override;
};

float Quadrado::calcularArea() const {
  return this->lado * this->lado;
}

class Pentagono:public Poligono {
  private:
    float lado;
    float apotema;
  public: 
    Pentagono(float lado, float apotema);
    virtual float calcularArea() const override;
};

Pentagono::Pentagono(float lado, float apotema) : Poligono(5) {
  this->lado = lado;
  this->apotema = apotema;
}

float Pentagono::calcularArea() const {
  return (this->getNumeroLados() * this->lado * this->apotema) / 2.0;
}


int main() {

     float lado, apotema;   

     cin >> lado;

     cin >> apotema;

     Poligono*ptr;

     ptr = new Quadrado(lado);

     cout << ptr->getNumeroLados();

     cout << ptr->calcularArea();

     ptr = new Pentagono(lado, apotema);

    cout << ptr->getNumeroLados();

     cout << ptr->calcularArea();

     return 0;

}
