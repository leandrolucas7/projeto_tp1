#include "../../include/dominios/DOMINIOS.hpp"
#include <cctype> // isalnum()
#include <regex>

bool Avaliacao::validar(int v)
{
    // Precisa validar se o input é do tipo certo?
    if (v >= 0 && v <= 5)
        return true;
    return false;
}

bool Avaliacao::set_valor(int v)
{
    if (!validar(v))
        return false;

    valor = v;
    return true;
}
