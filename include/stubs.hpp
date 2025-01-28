#ifndef stubs_HPP
#define stubs_HPP

#include "dominios/DOMINIOS.hpp"
#include "entidades/ENTIDADES.hpp"
#include "interfaces.hpp"

class StubCntrAprCriarConta: public IntAprCriarConta
{
    public:
        void criar();
};

class StubCntrAprAutenticacao:public IntAprAutenticacao
{
    public:
        bool autenticar(Conta*) override;
};

class StubAprEscolha: public IntAprEscolha
{
    public:
        void escolher_entidade() override;
};

class StubCntrSerAutenticacao: public IntSerAutenticacao
{
    private:
    
    public:
    bool autenticar(Conta) override;
};


#endif