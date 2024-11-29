#ifndef TESTE_DINHEIRO_HPP
#define TESTE_DINHEIRO_HPP

#include "super_teste.hpp"

class TesteDinheiro : public SuperTeste<double>
{
    protected:
        void set_valores() override;
};

#endif
