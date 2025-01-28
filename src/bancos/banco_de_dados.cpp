#include <iostream>
#include <stdexcept>
#include "../../include/bancos/banco_de_dados.hpp"
#include "../../include/entidades/ENTIDADES.hpp"

using namespace std;

template <typename T, typename U>
void BancoDados<T, U>::verificar(string codigo)
{
    if (dados.find(codigo) != dados.end())
        return;
    throw invalid_argument("Argumento (" + codigo + ") inválido.");

}


template <typename T, typename U>
T BancoDados<T, U>::ler(string codigo)
{
    verificar(codigo);
    return dados[codigo];
}


template <typename T, typename U>
bool BancoDados<T, U>::excluir(string codigo)
{
    verificar(codigo);
    dados.erase(codigo);
    return true;
}


template class BancoDados<Hospedagem, string>;
