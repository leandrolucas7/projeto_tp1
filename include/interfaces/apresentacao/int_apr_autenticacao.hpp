#ifndef IntAprAutenticacao_HPP
#define IntAprAutenticacao_HPP

#include "../../entidades/conta.hpp"


class IntAprAutenticacao
{
    public:
        virtual bool autenticar(Conta*) = 0;
};

#endif