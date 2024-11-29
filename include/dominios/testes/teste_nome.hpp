#ifndef TESTE_NOME_HPP
#define TESTE_NOME_HPP

#include "super_teste.hpp"
#include <string>
using namespace std;

class TesteNome : public SuperTeste<string>
{
    protected:
        void set_valores() override;
};

#endif
