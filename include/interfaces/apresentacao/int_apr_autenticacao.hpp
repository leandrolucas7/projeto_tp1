#ifndef IntAprAutenticacao_HPP
#define IntAprAutenticacao_HPP

#include "../../dominios/codigo.hpp"
#include "../../dominios/senha.hpp"


class IntAprAutenticacao
{
    public:
        virtual bool autenticar(Codigo*,Senha*) = 0;
};

#endif