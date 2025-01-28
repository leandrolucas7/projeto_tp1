#ifndef IntSerAutenticacao_HPP
#define IntSerAutenticacao_HPP


#include "../../entidades/conta.hpp"


class IntSerAutenticacao
{
    public:
        virtual bool autenticar(Conta) = 0;
};

#endif