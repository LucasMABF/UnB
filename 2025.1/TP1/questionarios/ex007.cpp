// Questionario aula 07
#include <iostream>

using namespace std;

class Poligono {
  private:
     string cor;
  public:
    Poligono(string cor): cor(cor) {};
    virtual ~Poligono(){}
    string getCor();
    virtual float calcularPerimetro() = 0;
};

inline string Poligono::getCor() {
  return this->cor;
}

class Paralelograma:public Poligono {
  private:
    float width;
    float height;
  public:
    Paralelograma(float width, float height, string cor): Poligono(cor), width(width), height(height){};
    virtual float calcularPerimetro() override;
};

float Paralelograma::calcularPerimetro() {
  return 2 * (this->width + this->height);
}

class Trapezio:public Poligono {
  private: 
    float B, b, l1, l2;
  public:
    Trapezio(float B, float b, float l1,float l2, string cor): Poligono(cor), B(B), b(b), l1(l1), l2(l2) {};
    virtual float calcularPerimetro() override;
};

float Trapezio::calcularPerimetro() {
  return this->B + this->b + this->l1 + this->l2;
}


int main() {

     Poligono*ptr;

     string cor;

     float a, b, B, L1, L2;  

     cin >> cor;

     cin >> a;

     cin >> b;

     cin >> B;

     cin >> L1;

     cin >> L2;

     ptr = new Paralelograma(a,b, cor);

     cout << ptr->getCor();

     cout << ptr->calcularPerimetro();

     delete ptr;

     ptr = new Trapezio(B, b, L1, L2, cor);

     cout << ptr->getCor();

     cout << ptr->calcularPerimetro();

     delete ptr;

     return 0;

}
