#include "../include/stubs.hpp"
#include <iostream>
#include <string>

void StubCntrAprCriarConta :: criar()
{
    cout << "StubCntrAprCriarConta" << endl;
    Conta conta;
    int entrada_do_usuario;
    while (true)
    {
        cout << "Essa eh a tela de criacao de conta. Escolha uma opcao:" << endl;
        cout << "1. Sair" << endl;
        cout << "2. Criar conta" << endl;
        cin >> entrada_do_usuario;
        switch (entrada_do_usuario)
        {
        case 1:
            return;
        case 2:
            try
            {
            string codigo_string;
            string senha_string;
            Codigo codigo;
            Senha senha;
            cout << "Digite o codigo:" << endl;
            cin >> codigo_string;
            codigo.set_valor(codigo_string);
            cout << "Digite a senha: " << endl;
            cin >> senha_string;
            senha.set_valor(senha_string);
            if (codigo_string != "654321")
                {
                    
                    //A conta seria adicionada ao banco de dados
                    cout << "Dados cadastrados no sistema!"  << endl;
                    return;
                }
            }
            catch(const invalid_argument& e)
            {
                cout << "Valor Invalido!" << endl;
            }
        default:
            cout << "Essa opcao nao existe !" << endl;
        }
    }
}

bool StubCntrAprAutenticacao::autenticar(Conta* conta_ptr)
{
    cout << "StubCntrAprAutenticacao" << endl;
    Conta* conta2 = new Conta();
    Codigo codigo2;
    Senha senha2;
    codigo2.set_valor("123456");
    senha2.set_valor("69130");
    conta2->set_codigo(codigo2);
    conta2->set_senha(senha2);
    string codigo_digitado;
    string senha_digitada;
    cout << "Digite codigo" << endl;
    cin >> codigo_digitado;
    cout << "Digite senha" << endl;
    cin >> senha_digitada;
    if (codigo_digitado == conta2->get_codigo().get_valor() && senha_digitada == conta2->get_senha().get_valor())
    {
        conta_ptr = conta2;
        return true;
    }
    else
        return false;
}


void StubAprEscolha :: escolher_entidade()
{
    cout << "StubAprEscolha" << endl;
    int entrada_do_usuario;
    cout << "Escolha uma das opções abaixo:" << endl;
    cout << "1. Sair" << endl;
    cout << "2. Viagem" << endl;
    cin >> entrada_do_usuario;
    switch (entrada_do_usuario)
    {
    case 1:
        return;
    case 2:
        cout << "ainda nao implementei essa parte, lembra, Rafael (>_<) ?";
        return;
    default:
        cout << "ainda nao implementei essa parte, lembra, Rafael (>_<) ?";
        return;
    }

}

bool StubCntrSerAutenticacao :: autenticar(Conta conta)
{
    cout << "StubCntrSerAutenticacao" << endl;
    if (conta.get_codigo().get_valor() == "123456" && conta.get_senha().get_valor() == "69130")
    {
        return true;
    }
    return false;
}