#ifndef TESTE_DATA_HPP
#define TESTE_DATA_HPP

#include "super_teste.hpp"
#include <string>
using namespace std;

class TesteData : public SuperTeste<string>
{
    protected:
        void set_valores() override;
};

#endif
