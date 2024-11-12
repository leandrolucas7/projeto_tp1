#ifndef DURACAO_CPP
#define DURACAO_CPP

#include "../../include/dominios/DOMINIOS.hpp"
#include <cctype> // isalnum()
#include <regex>

bool Duracao::validar(int v)
{
    if (v >= 0 && v <= 360)
        return true;
    return false;
}

bool Duracao::set_valor(int v)
{
    if (!validar(v))
        return false;
    valor = v;
    return true;
}


#endif
