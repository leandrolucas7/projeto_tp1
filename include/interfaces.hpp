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

template <typename T, typename U>
class IntAprCRU
{
      private:
            IntSerCUD* servico;
      public:
            virtual void create(T*) = 0;
            virtual void read(U*) = 0;
            virtual void update(U*) = 0;
            //virtual void remove() = 0;
};

class IntSerCUD
{
    public:
        virtual void create() = 0;
        //virtual void read() = 0;
        virtual void update() = 0;
        virtual void remove() = 0;
};


class IntSerAutenticacao
{
    public:
        virtual bool autenticar(Conta) = 0;
};

#endif