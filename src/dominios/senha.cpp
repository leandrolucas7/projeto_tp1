#include "../../include/dominios/DOMINIOS.hpp"
#include <cctype> // isalnum()
#include <regex>

void Senha::validar(string v)
{
    bool crescente = true;
    bool decrescente = true;
    
    if (v.length() != 5)
        return false;

    // verificando se é digito
    for (char c: v)
    {
        if (!isdigit(c))
            return false;
    }

    // verificando se há digitos repetidos
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (v[i] == v[j])
                return false;
        }
    }
    
    //verificando se está em ordem crescente ou decrescente
    for (int i = 0; i < 4; i++)
    {
        if (v[i+1] < v[i])
            crescente = false;
        if (v[i+1] > v[i])
            decrescente = false;
    }

    if (crescente || decrescente)
        return false;
    return true;
}
