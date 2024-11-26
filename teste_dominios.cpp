#include <iostream>
#include <stdexcept>
#include "include/dominios/DOMINIOS.hpp"
#include "include/entidades/ENTIDADES.hpp"
using namespace std;

int main()
{
    cout << "Avaliacao: " << endl; 
    Avaliacao avaliacao;
    try
    {
        avaliacao.set_valor(1);
        cout << avaliacao.get_valor() << endl;
    }
    catch(invalid_argument &exp)
    {
        cout << "Excecao: " << exp.what() << endl;
    }
    try
    {
        avaliacao.set_valor(7);
        cout << avaliacao.get_valor() << endl;
    }
    catch(invalid_argument &exp)
    {
        cout << "Excecao: " << exp.what() << endl;
    }

    cout << "Codigo:" << endl;
    Codigo codigo;
    try
    {
        codigo.set_valor("123456");
        cout << codigo.get_valor() << endl;
    }
    catch(invalid_argument &exp)
    {
        cout << "Excecao: " << exp.what() << endl;
    }
    try
    {
        codigo.set_valor("1A34");
        cout << codigo.get_valor() << endl;
    }
    catch(invalid_argument &exp)
    {
        cout << "Excecao: " << exp.what() << endl;
    }

    cout << "Data:" << endl;
    Data data;
    try
    {
        data.set_valor("12-03-96");
        cout << data.get_valor() << endl;
    }
    catch(invalid_argument &exp)
    {
        cout << "Excecao: " << exp.what() << endl;
    }
    try
    {
        data.set_valor("29-02-23");
        cout << data.get_valor() << endl;
    }
    catch(invalid_argument &exp)
    {
        cout << "Excecao: " << exp.what() << endl;
    }

    cout << "Dinheiro:" << endl;
    Dinheiro dinheiro;
    try
    {
        dinheiro.set_valor(25.45);
        cout << dinheiro.get_valor() << endl;
    }
    catch(invalid_argument &exp)
    {
        cout << "Excecao: " << exp.what() << endl;
    }
    try
    {
        dinheiro.set_valor(12.345);
        cout << dinheiro.get_valor() << endl;
    }
    catch(invalid_argument &exp)
    {
        cout << "Excecao: " << exp.what() << endl;
    }


    cout << "Duracao:" << endl;
    Duracao duracao;
    try 
    {
        duracao.set_valor(50);
        cout << duracao.get_valor() << endl;
    }
    catch(invalid_argument &exp)
    {
        cout << "Excecao: " << exp.what() << endl;
    }
    try 
    {
        duracao.set_valor(50000);
        cout << duracao.get_valor() << endl;
    }
    catch(invalid_argument &exp)
    {
        cout << "Excecao: " << exp.what() << endl;
    }


    cout << "Horario" << endl;
    Horario horario;
    try 
    {
        horario.set_valor("20:45");
        cout << horario.get_valor() << endl;
    }
    catch(invalid_argument &exp)
    {
        cout << "Excecao: " << exp.what() << endl;
    }
    try 
    {
        horario.set_valor("25:00");
        cout << horario.get_valor() << endl;
    }
    catch(invalid_argument &exp)
    {
        cout << "Excecao: " << exp.what() << endl;
    }


    cout << "Nome" << endl;
    Nome nome;
    try
    {
        nome.set_valor("viniccius 13");
        cout << nome.get_valor() << endl;
    }
    catch(invalid_argument &exp)
    {
        cout << "Excecao: " << exp.what() << endl;
    }
    try
    {
        nome.set_valor("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
        cout << nome.get_valor() << endl;
    }
    catch(invalid_argument &exp)
    {
        cout << "Excecao: " << exp.what() << endl;
    }


    cout << "Senha" << endl;
    Senha senha;
    try
    {
        senha.set_valor("48956");
        cout << senha.get_valor() << endl;
    }
    catch(invalid_argument &exp)
    {
        cout << "Excecao: " << exp.what() << endl;
    }
    try
    {
        senha.set_valor("48946");
        cout << senha.get_valor() << endl;
    }
    catch(invalid_argument &exp)
    {
        cout << "Excecao: " << exp.what() << endl;
    }
}
