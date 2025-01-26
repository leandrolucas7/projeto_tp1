#include "../include/controladores.hpp"
#include "../include/stubs.hpp"


using namespace std;

CntrAprInicial::CntrAprInicial()
{
    this->cntrAprCriarConta = new StubCntrAprCriarConta();
    this->cntrAprAutenticacao = new StubCntrAprAutenticacao();
    this->cntrAprEscolha = new StubAprEscolha();
};


void CntrAprInicial::executar()
{
    Conta* conta_ptr = nullptr;
    usuarioLogado = false;
    int entrada_do_usuario;
    while (!usuarioLogado)
    {
        cout << "Essa eh a tela inicial. Selecione uma das opcoes abaixo:" << endl;
        cout << "1. Criar conta" << endl;
        cout << "2. Login" << endl;
        cout << "3. Sair" << endl;
        cin >> entrada_do_usuario;
        switch(entrada_do_usuario)
        {
        case 1:
            this->cntrAprCriarConta->criar();
            continue;
        case 2:
            usuarioLogado = this->cntrAprAutenticacao->autenticar(conta_ptr);
            break;
        case 3: 
            return;
        default:
            cout << "Essa opcao nao existe !" << endl;
        }

        while (usuarioLogado)
        {
            cout << "Essa eh a tela para usuarios logados. Selecione uma das opcoes" << endl;
            cout << "1. Logout" << endl;
            cout << "2. Entrar" << endl;
            cin >> entrada_do_usuario;
            switch (entrada_do_usuario)
            {
            case 1:
                conta_ptr = nullptr;
                usuarioLogado = false;
                break;
            case 2:
                this->cntrAprEscolha->escolher_entidade();
                continue;
            default:
                break;
            }
        }
    }
    
}

bool CntrAprAutenticacao::autenticar(Conta* conta)
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

    StubCntrSerAutenticacao* mod_ser_autenticacao = new StubCntrSerAutenticacao();
    return mod_ser_autenticacao->autenticar(*conta);
}


void cntrAprCRUViagem::create(Conta*)
{
    
}
