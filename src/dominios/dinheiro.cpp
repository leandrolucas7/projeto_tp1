#ifndef DINHEIRO_CPP
#define DINHEIRO_CPP

#include "../../include/dominios/DOMINIOS.hpp"
#include <cctype> // isalnum()
#include <regex>

bool Dinheiro::validar(double v)
{
    int novo_valor = static_cast<int>(v * 100);
    if ((novo_valor >= 0 && novo_valor <= 20000000) && (v * 100 - novo_valor == 0))
        return true;
    return false;
}

bool Dinheiro::set_valor(double v)
{
    if (!validar(v))
        return false;
    int novo_valor = static_cast<int>(v * 100);
    valor = novo_valor;
    return true;
}


#endif
