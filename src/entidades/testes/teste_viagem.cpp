#include "../../../include/entidades/testes/teste_viagem.hpp"
#include <iostream>
#include <stdexcept>

const vector<string> TesteViagem::VALORES_VALIDOS_CODIGO = {"A1b2C3", "aAbBcC", "123456", "unb100"};
const vector<string> TesteViagem::VALORES_VALIDOS_NOME = {"16-12-24","29-09-16","31-01-23","00-05-00"};
const vector<int> TesteViagem::VALORES_VALIDOS_AVALIACAO = {0, 1, 2, 3, 4, 5};

void TesteViagem::set_up()
{
    viagem = new Viagem();
    estado = SUCESSO;
}

void TesteViagem::tear_down()
{   
    delete viagem;
    viagem = nullptr;
}

void TesteViagem::testar_cenario()
{
    Codigo codigo;
    for (string valor : VALORES_VALIDOS_CODIGO)
    {
        try
        {
            codigo.set_valor(valor);
            viagem->set_codigo(codigo);
            if (viagem->get_codigo().get_valor() != valor)
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
            viagem->set_nome(nome);
            if (viagem->get_nome().get_valor() != valor)
                estado = FALHA;
        }
        catch (invalid_argument &exp)
        {
            estado = FALHA;
        }

        if (estado == FALHA)
            throw invalid_argument("FALHA: Argumento válido (" + valor + ") não validado");
    }
    Avaliacao avaliacao;
    for (int valor : VALORES_VALIDOS_AVALIACAO)
    {
        try
        {
            avaliacao.set_valor(valor);
            viagem->set_avaliacao(avaliacao);
            if (viagem->get_avaliacao().get_valor() != valor)
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

int TesteViagem::run()
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