#include "../../include/dominios/DOMINIOS.hpp"

bool Avaliacao::validar(int v)
{
    if (v >= 0 && v <= 5)
        return true;
    return false;
}

