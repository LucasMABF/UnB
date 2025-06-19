#ifndef DOMINIOS_HPP_INCLUDED

#define DOMINIOS_HPP_INCLUDED

class CodigoCliente {
  private:
    static const int LIMITE = 5;
    static const int DEFAULT = 0;
    int valor;
    bool validar(int);
  public:
    bool setValor(int);
    int getValor();
  
};

inline int CodigoCliente::getValor() {
  return valor;
}

#endif
