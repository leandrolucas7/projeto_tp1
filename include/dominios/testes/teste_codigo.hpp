#ifndef TESTE_CODIGO_HPP
#define TESTE_CODIGO_HPP

#include "super_teste.hpp"
#include <string>
using namespace std;

class TesteCodigo : public SuperTeste<string>
{
    protected:
        void set_valores() override;
};

#endif

