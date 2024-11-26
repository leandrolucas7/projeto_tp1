#ifndef TESTE_AVALIACAO_HPP
#define TESTE_AVALIACAO_HPP

#include "super_teste.hpp"

class TesteAvaliacao : public SuperTeste<int>
{
    protected:
        void set_valores() override;
};

#endif
