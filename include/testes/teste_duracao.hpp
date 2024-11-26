#ifndef TESTE_DURACAO_HPP
#define TESTE_DURACAO_HPP

#include "super_teste.hpp"

class TesteDuracao : public SuperTeste<int>
{
    protected:
        void set_valores() override;
};

#endif
