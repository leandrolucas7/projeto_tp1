#include "../../../include/entidades/testes/teste_conta.hpp"
#include <iostream>
#include <stdexcept>

const vector<string> TesteConta::VALORES_VALIDOS_CODIGO = {"A1b2C3", "aAbBcC", "123456", "unb100"};
const vector<string> TesteConta::VALORES_VALIDOS_SENHA = {"12435", "54812", "20591", "04521", "45210"};

void TesteConta::set_up()
{
    conta = new Conta();
    estado = SUCESSO;
}

void TesteConta::tear_down()
{   
    delete conta;
    conta = nullptr;
}

void TesteConta::testar_cenario()
{
    Codigo codigo;
    for (string valor : VALORES_VALIDOS_CODIGO)
    {
        try
        {
            codigo.set_valor(valor);
            conta->set_codigo(codigo);
            if (conta->get_codigo().get_valor() != valor)
                estado = FALHA;
        }
        catch (invalid_argument &exp)
        {
            estado = FALHA;
        }

        if (estado == FALHA)
            throw invalid_argument("FALHA: Argumento válido (" + valor + ") não validado");
    }

    Senha senha;
    for (string valor : VALORES_VALIDOS_SENHA)
    {
        try
        {
            senha.set_valor(valor);
            conta->set_senha(senha);
            if (conta->get_senha().get_valor() != valor)
                estado = FALHA;
        }
        catch (invalid_argument &exp)
        {
            estado = FALHA;
        }

        if (estado == FALHA)
            throw invalid_argument("FALHA: Argumento válido (" + valor + ") não validado");
    }
}

int TesteConta::run()
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
