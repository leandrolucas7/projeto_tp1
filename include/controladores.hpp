#include "./interfaces.hpp"
#include "./commands.hpp"
#include "./stubs.hpp"
#include "dominios/DOMINIOS.hpp"
#include "entidades/ENTIDADES.hpp"

class ModAprAutenticacao : public IntAprAutenticacao
{
    public:
        bool autenticar(Conta*) override;
};



class ModSerAutenticacao : public IntSerAutenticacao
{
    public:
        bool autenticar(Conta) override;
};