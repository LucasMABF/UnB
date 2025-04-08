#ifndef DOMINIOS_HPP_INCLUDED

#define DOMINIOS_HPP_INCLUDED

class CodigoCliente {
  private:
    static const int LIMITE = 5;
    static const int DEFAULT = 0;
    int valor = -1;
    bool validar(int);
  public:
    bool setValor(int);
    int getValor();
  
};

inline int CodigoCliente::getValor() {
  return this->valor;
}

class Prioridade {
  private:
    static const int INVALIDO = 0;
    int valor;
    bool validar(int);

  public:
    bool setValor(int);
    int getValor();
};

inline int Prioridade::getValor() {
  return this->valor;
}

#endif
