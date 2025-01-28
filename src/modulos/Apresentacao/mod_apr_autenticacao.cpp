#include "../../../include/modulos/apresentacao/mod_apr_autenticacao.hpp"
#include "../../stubs/stub_mod_ser_autenticacao.cpp"
#include "../../../include/entidades/conta.hpp"
#include "../../../include/dominios/codigo.hpp"
#include "../../../include/dominios/senha.hpp"
#include <iostream>
#include <string>
using namespace std;

bool ModAprAutenticacao::autenticar(Conta* conta)
{   
    Codigo codigo;
    Senha senha;
    string codigo_string;
    string senha_string;
    bool flag;

    flag = false;
    while (!flag)
    {
        flag = true;
        cout << "Código: " << endl;
        cin >> codigo_string;
        if (codigo_string == "logout")
            return false; 
        try
        {
            codigo.set_valor(codigo_string);
        }
        catch(const invalid_argument& e)
        {
            cerr << "Código inválido" << '\n';
            flag = false;
        }
    }

    flag = false;
    while (!flag)
    {
        flag = true;
        cout << "Senha: " << endl;
        cin >> senha_string;
        if (senha_string == "logout")
            return false;
        try
        {
            senha.set_valor(senha_string);
        }
        catch(const invalid_argument& e)
        {
            cerr << "Senha inválida" << '\n';
            flag = false;
        }
    }
    conta->set_codigo(codigo);
    conta->set_senha(senha);

    StubModSerAutenticacao* mod_ser_autenticacao = new StubModSerAutenticacao();
    return mod_ser_autenticacao->autenticar(*conta);
}
