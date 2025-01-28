#include "../../include/bancos/banco_de_dados.hpp"
#include "../../include/bancos/banco_hospedagens.hpp"
#include "../../include/entidades/ENTIDADES.hpp"

#include <iostream>
using namespace std;

bool BancoHospedagens::criar(string codigo, string senha)
{
    Hospedagem h1;
    dados[codigo] = h1;
    cout << "metodo criar da hospedagem!!!" << endl;
    return true;
}


bool BancoHospedagens::atualizar(string codigo, string novo_valor)
{
    cout << "metodo atualizar da hospedagem!!!" << endl;
    return true;
}