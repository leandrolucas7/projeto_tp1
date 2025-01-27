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

class IntAprCRUDConta
{
    public:
        virtual void create(Conta*) = 0;
        virtual void read(Conta*) = 0;
        virtual void update(Conta*) = 0;
        virtual void destroy(Conta*) = 0;
};

template <typename T, typename U>
class IntAprCRUD
{
    private:
        IntSerCUD* servico;
    public:
        virtual void create(T*) = 0;
        virtual void read(T*,U*) = 0;
        virtual void update(T*,U*) = 0;
        virtual void destroy(T*,U*) = 0;
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