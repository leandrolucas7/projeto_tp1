#include "../../include/dominios/DOMINIOS.hpp"
#include <cctype> // isalnum()
#include <regex>

bool Duracao::validar(int v)
{
    if (v >= 0 && v <= 360)
        return true;
    return false;
}

