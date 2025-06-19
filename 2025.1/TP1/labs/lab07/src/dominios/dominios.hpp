#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

class Dominio {
 private:
  int valor;
  virtual bool validar(int) = 0;

 public:
  bool setValor(int);
  int getValor() const;
  virtual ~Dominio() = default;
};

inline int Dominio::getValor() const { return this->valor; }

class DominioA1 : public Dominio {
 private:
  bool validar(int) override;
};

class DominioA2 : public Dominio {
 private:
  bool validar(int) override;
};

class DominioB1 : public Dominio {
 private:
  bool validar(int) override;
};

class DominioB2 : public Dominio {
 private:
  bool validar(int) override;
};

#endif
