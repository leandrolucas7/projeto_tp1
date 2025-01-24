#ifndef interfacesHPP
#define interfacesHPP

#include "dominios/DOMINIOS.hpp"
#include "entidades/ENTIDADES.hpp"

class IntAprCriarConta
{
    public:
        virtual void criar() = 0;
        //virtual void executar(Conta) = 0;
};

class IntAprAutenticacao
{
    public:
        virtual bool autenticar(Conta*) = 0;
};


class IntAprEscolha
{
    public:
        virtual void escolher_entidade() = 0;
};

class IntSerAutenticacao
{
    public:
        virtual bool autenticar(Conta) = 0;
};

#endif