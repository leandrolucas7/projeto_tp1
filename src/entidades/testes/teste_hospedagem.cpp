#include "../../../include/entidades/testes/teste_hospedagem.hpp"
#include <iostream>
#include <stdexcept>

const vector<string> TesteHospedagem::VALORES_VALIDOS_CODIGO = {"A1b2C3", "aAbBcC", "123456", "unb100"};
const vector<string> TesteHospedagem::VALORES_VALIDOS_NOME = {"16-12-24","29-09-16","31-01-23","00-05-00"};
const vector<double> TesteHospedagem:: VALORES_VALIDOS_DIARIA = {0.00, 2000, 50};
const vector<int> TesteHospedagem::VALORES_VALIDOS_AVALIACAO = {0, 1, 2, 3, 4, 5};

void TesteHospedagem::set_up()
{
    hospedagem = new Hospedagem();
    estado = SUCESSO;
}

void TesteHospedagem::tear_down()
{   
    delete hospedagem;
    hospedagem = nullptr;
}

void TesteHospedagem::testar_cenario()
{
    Codigo codigo;
    for (string valor : VALORES_VALIDOS_CODIGO)
    {
        try
        {
            codigo.set_valor(valor);
            hospedagem->set_codigo(codigo);
            if (hospedagem->get_codigo().get_valor() != valor)
                estado = FALHA;
        }
        catch (invalid_argument &exp)
        {
            estado = FALHA;
        }

        if (estado == FALHA)
            throw invalid_argument("FALHA: Argumento válido (" + valor + ") não validado");
    }
    Nome nome;
    for (string valor : VALORES_VALIDOS_NOME)
    {
        try
        {
            nome.set_valor(valor);
            hospedagem->set_nome(nome);
            if (hospedagem->get_nome().get_valor() != valor)
                estado = FALHA;
        }
        catch (invalid_argument &exp)
        {
            estado = FALHA;
        }

        if (estado == FALHA)
            throw invalid_argument("FALHA: Argumento válido (" + valor + ") não validado");
    }
    Dinheiro diaria;
    for (double valor : VALORES_VALIDOS_DIARIA)
    {
        try
        {
            diaria.set_valor(valor);
            hospedagem->set_diaria(diaria);
            if (hospedagem->get_diaria().get_valor() != valor)
                estado = FALHA;
        }
        catch (invalid_argument &exp)
        {
            estado = FALHA;
        }

        if (estado == FALHA)
            throw invalid_argument("FALHA: Argumento válido (" + to_string(valor) + ") não validado");
    }
    Avaliacao avaliacao;
    for (int valor : VALORES_VALIDOS_AVALIACAO)
    {
        try
        {
            avaliacao.set_valor(valor);
            hospedagem->set_avaliacao(avaliacao);
            if (hospedagem->get_avaliacao().get_valor() != valor)
                estado = FALHA;
        }
        catch (invalid_argument &exp)
        {
            estado = FALHA;
        }

        if (estado == FALHA)
            throw invalid_argument("FALHA: Argumento válido (" + to_string(valor) + ") não validado");
    }
}

int TesteHospedagem::run()
{
    set_up();
    try
    {
        testar_cenario();
    }
    catch(invalid_argument &exp)
    {
        cout << exp.what() << endl;
    }
    tear_down();
    return estado; 
}