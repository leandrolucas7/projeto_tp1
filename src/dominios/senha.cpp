#include "../../include/dominios/DOMINIOS.hpp"
#include <cctype> // isalnum()
#include <regex>
#include <stdexcept>

void Senha::validar(string v)
{
    bool flag = true;
    bool crescente = true;
    bool decrescente = true;
    
    if (v.length() != 5)
        flag = false;

    // verificando se é digito
    for (char c: v)
    {
        if (!isdigit(c))
            flag = false;
    }

    // verificando se há digitos repetidos
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (v[i] == v[j])
                flag = false;
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
        flag = false;
    if (flag)
        return;
    //throw invalid_argument("Argumento (" + v + ") inválido.");
    throw invalid_argument("Formato invalido! A senha deve ter 5 digitos, sem repeticao, sem ordem crescente e sem ordem decrescente");
}


bool operator==(const Senha &senha1, const Senha &senha2)
{
    return senha1.valor == senha2.valor;
}