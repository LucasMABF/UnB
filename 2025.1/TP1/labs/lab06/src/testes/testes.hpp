#ifndef TESTES_HPP_INCLUDED
#define TESTES_HPP_INCLUDED

#include "dominios/dominios.hpp"
#include "entidades/entidades.hpp"

class StubDominio: public Dominio {
  private:
    virtual void validar(int valido) const override;
};

class TUDominio {
  private:
    const static int VALOR_VALIDO = 1;
    const static int VALOR_INVALIDO = 0;
    StubDominio *dominio;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioValido();
    void testarCenarioInvalido();
  public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();
};

inline void TUDominio::setUp() {
  this->dominio = new StubDominio;
  this->estado = TUDominio::SUCESSO;
}

inline void TUDominio::tearDown() {
  delete this->dominio;
}

class TUProjeto {
  private:
    const static int VALOR_VALIDO = 4;
    Projeto *projeto;
    int estado;
    void setUp();
    void tearDown();
    void testarCenario();
  public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();
};

inline void TUProjeto::setUp() {
  this->projeto = new Projeto;
  this->estado = TUProjeto::SUCESSO;
}

inline void TUProjeto::tearDown() {
  delete this->projeto;
}

#endif
