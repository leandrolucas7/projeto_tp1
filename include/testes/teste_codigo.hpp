#ifndef TESTE_CODIGO_HPP
#define TESTE_CODIGO_HPP

using namespace std;
#include "super_teste.hpp"
#include <string>


class TesteCodigo : public SuperTeste<string>
{
    protected:
        void set_valores() override;
};

#endif;

