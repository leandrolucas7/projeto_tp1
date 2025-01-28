#include "../../include/bancos/banco_de_dados.hpp"
#include "../../include/bancos/banco_hospedagens.hpp"
#include "../../include/entidades/ENTIDADES.hpp"
#include "../../include/dominios/DOMINIOS.hpp"

#include <iostream>
using namespace std;

bool BancoHospedagens::criar(Hospedagem valor)
{
    //dados[valor.get_codigo().get_valor()] = valor;
    dados["abc"] = valor;
    cout << "metodo criar da hospedagem!!!" << endl;
    return true;
}


bool BancoHospedagens::atualizar(Hospedagem novo_valor)
{
    cout << "metodo atualizar da hospedagem!!!" << endl;
    return true;
}


// Provisório para testes
BancoHospedagens::BancoHospedagens()
{
    Codigo codigo1;
    codigo1.set_valor("123456");
    Nome nome1;
    nome1.set_valor("Nome1");
    Dinheiro dinheiro1;
    dinheiro1.set_valor(200);
    Avaliacao avaliacao1;
    avaliacao1.set_valor(4);
    Hospedagem h1;
    h1.set_codigo(codigo1);
    h1.set_nome(nome1);
    h1.set_diaria(dinheiro1);
    h1.set_avaliacao(avaliacao1);
    criar(h1);
}

void BancoHospedagens::test()
{
    cout << dados["abc"].get_nome().get_valor() << endl;
    atualizar(dados["abc"]);
}
    