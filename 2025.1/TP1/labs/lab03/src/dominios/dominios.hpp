#ifndef DOMINIOS_HPP_INCLUDED

#define DOMINIOS_HPP_INCLUDED

class Dominio {
  private: 
    int valor;
    virtual bool validar(int) const = 0;
  public: 
    bool setValor(int);
    int getValor() const;
};

inline int Dominio::getValor() const {
  return this->valor;
}

class CodigoCliente:public Dominio {
  private:
    static const int LIMITE = 5;
    virtual bool validar(int) const override;
};

class Prioridade:public Dominio{
  private:
    static const int INVALIDO = 0;
    virtual bool validar(int) const override;
};

#endif
