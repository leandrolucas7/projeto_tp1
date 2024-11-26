#include "../../include/dominios/DOMINIOS.hpp"
#include <cctype> // isalnum()
#include <regex>
#include <stdexcept>

void Codigo::validar(string v)
{
    bool flag = true;
    const int TAMANHO_CODIGO = 6;
    if (v.length() != TAMANHO_CODIGO)
        flag = false;
    for (int i = 0; i < TAMANHO_CODIGO; i++)
    {
        if (! isalnum(v[i]))
            flag = false;
    }
    if (flag)
        return;
    throw invalid_argument("Argumento (" + v + ") inválido.");
}

