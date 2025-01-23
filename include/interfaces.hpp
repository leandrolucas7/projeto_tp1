#include "dominios/DOMINIOS.hpp"
#include "entidades/ENTIDADES.hpp"

class IntAprAutenticacao
{
    public:
        virtual bool autenticar(Conta*) = 0;
};

class IntAprConta
{
    public:
        void criar();
        void executar(Conta);
};

class IntSerAutenticacao
{
    public:
        virtual bool autenticar(Conta) = 0;
};