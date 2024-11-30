#include "../../../include/entidades/testes/teste_destino.hpp"
#include <iostream>
#include <stdexcept>

const vector<string> TesteDestino::VALORES_VALIDOS_CODIGO = {"A1b2C3", "aAbBcC", "123456", "unb100"};
const vector<string> TesteDestino::VALORES_VALIDOS_NOME = {"16-12-24","29-09-16","31-01-23","00-05-00"};
const vector<string> TesteDestino::VALORES_VALIDOS_DATA_INICIO = {"16-12-24","29-09-16","31-01-23","01-05-00"};
const vector<string> TesteDestino::VALORES_VALIDOS_DATA_TERMINO = {"21-12-27","29-10-80","31-05-27","02-05-00"};
const vector<int> TesteDestino::VALORES_VALIDOS_AVALIACAO = {0, 1, 2, 3, 4, 5};

void TesteDestino::set_up()
{
    destino = new Destino();
    estado = SUCESSO;
}

void TesteDestino::tear_down()
{   
    delete destino;
    destino = nullptr;
}

void TesteDestino::testar_cenario()
{
    Codigo codigo;
    for (string valor : VALORES_VALIDOS_CODIGO)
    {
        try
        {
            codigo.set_valor(valor);
            destino->set_codigo(codigo);
            if (destino->get_codigo().get_valor() != valor)
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
            destino->set_nome(nome);
            if (destino->get_nome().get_valor() != valor)
                estado = FALHA;
        }
        catch (invalid_argument &exp)
        {
            estado = FALHA;
        }

        if (estado == FALHA)
            throw invalid_argument("FALHA: Argumento válido (" + valor + ") não validado");
    }
    Data data_inicio;
    for (string valor : VALORES_VALIDOS_DATA_INICIO)
    {
        try
        {
            data_inicio.set_valor(valor);
            destino->set_data_inicio(data_inicio);
            if (destino->get_data_inicio().get_valor() != valor)
                estado = FALHA;
        }
        catch (invalid_argument &exp)
        {
            estado = FALHA;
        }

        if (estado == FALHA)
            throw invalid_argument("FALHA: Argumento válido (" + valor + ") não validado");
    }
    Data data_termino;
    for (string valor : VALORES_VALIDOS_DATA_TERMINO)
    {
        try
        {
            data_termino.set_valor(valor);
            destino->set_data_termino(data_termino);
            if (destino->get_data_termino().get_valor() != valor)
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
            destino->set_avaliacao(avaliacao);
            if (destino->get_avaliacao().get_valor() != valor)
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

int TesteDestino::run()
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