#include "../../../include/entidades/testes/teste_atividade.hpp"
#include <iostream>
#include <stdexcept>

const vector<string> TesteAtividade:: VALORES_VALIDOS_CODIGO = {"A1b2C3", "aAbBcC", "123456", "unb100"};
const vector<string> TesteAtividade:: VALORES_VALIDOS_NOME = {"16-12-24","29-09-16","31-01-23","00-05-00"};
const vector<string> TesteAtividade:: VALORES_VALIDOS_DATA = {"16-12-24","29-09-16","31-01-23","01-05-00"};
const vector<string> TesteAtividade:: VALORES_VALIDOS_HORARIO = {"00:15", "14:30", "23:59"};
const vector<int> TesteAtividade:: VALORES_VALIDOS_DURACAO = {360, 1, 68, 34};
const vector<double> TesteAtividade:: VALORES_VALIDOS_PRECO = {0.00, 2000, 50};
const vector<int> TesteAtividade:: VALORES_VALIDOS_AVALIACAO = {0, 1, 2, 3, 4, 5};

void TesteAtividade::set_up()
{
    atividade = new Atividade();
    estado = SUCESSO;
}

void TesteAtividade::tear_down()
{   
    delete atividade;
    atividade = nullptr;
}

void TesteAtividade::testar_cenario()
{
    Codigo codigo;
    for (string valor : VALORES_VALIDOS_CODIGO)
    {
        try
        {
            codigo.set_valor(valor);
            atividade->set_codigo(codigo);
            if (atividade->get_codigo().get_valor() != valor)
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
            atividade->set_nome(nome);
            if (atividade->get_nome().get_valor() != valor)
                estado = FALHA;
        }
        catch (invalid_argument &exp)
        {
            estado = FALHA;
        }

        if (estado == FALHA)
            throw invalid_argument("FALHA: Argumento válido (" + valor + ") não validado");
    }
    Data data;
    for (string valor : VALORES_VALIDOS_DATA)
    {
        try
        {
            data.set_valor(valor);
            atividade->set_data(data);
            if (atividade->get_data().get_valor() != valor)
                estado = FALHA;
        }
        catch (invalid_argument &exp)
        {
            estado = FALHA;
        }

        if (estado == FALHA)
            throw invalid_argument("FALHA: Argumento válido (" + valor + ") não validado");
    }
    Horario horario;
    for (string valor : VALORES_VALIDOS_HORARIO)
    {
        try
        {
            horario.set_valor(valor);
            atividade->set_horario(horario);
            if (atividade->get_horario().get_valor() != valor)
                estado = FALHA;
        }
        catch (invalid_argument &exp)
        {
            estado = FALHA;
        }

        if (estado == FALHA)
            throw invalid_argument("FALHA: Argumento válido (" + valor + ") não validado");
    }
    Duracao duracao;
    for (int valor : VALORES_VALIDOS_DURACAO)
    {
        try
        {
            duracao.set_valor(valor);
            atividade->set_duracao(duracao);
            if (atividade->get_duracao().get_valor() != valor)
                estado = FALHA;
        }
        catch (invalid_argument &exp)
        {
            estado = FALHA;
        }

        if (estado == FALHA)
            throw invalid_argument("FALHA: Argumento válido (" + to_string(valor) + ") não validado");
    }
    Dinheiro preco;
    for (double valor : VALORES_VALIDOS_PRECO)
    {
        try
        {
            preco.set_valor(valor);
            atividade->set_preco(preco);
            if (atividade->get_preco().get_valor() != valor)
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
            atividade->set_avaliacao(avaliacao);
            if (atividade->get_avaliacao().get_valor() != valor)
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

int TesteAtividade::run()
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