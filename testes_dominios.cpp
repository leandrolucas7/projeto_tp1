#include <iostream>
#include <string>
#include "include/dominios/DOMINIOS.hpp"
#include "include/testes/TESTES.hpp"

using namespace std;
int main()
{
    TesteAvaliacao teste_avaliacao;
    cout << "AVALIACAO:" << endl << "    ";
    if (teste_avaliacao.run() == TesteAvaliacao::SUCESSO)
        cout << "Teste 'AVALIACAO' bem-sucedido" << endl;

    TesteCodigo teste_codigo;
    cout << "CODIGO:" << endl << "    ";
    if (teste_codigo.run() == TesteCodigo::SUCESSO)
        cout << "Teste 'CODIGO' bem-sucedido" << endl;

    TesteData teste_data;
    cout << "DATA:" << endl << "    ";
    if (teste_data.run() == TesteData::SUCESSO)
        cout << "Teste 'DATA' bem-sucedido" << endl;

    TesteDinheiro teste_dinheiro;
    cout << "DINHEIRO:" << endl << "    ";
    if (teste_dinheiro.run() == TesteDinheiro::SUCESSO)
        cout << "Teste 'DINHEIRO' bem-sucedido" << endl;

    TesteDuracao teste_duracao;
    cout << "DURACAO:" << endl << "    ";
    if (teste_duracao.run() == TesteDuracao::SUCESSO)
        cout << "Teste 'DURACAO' bem-sucedido" << endl;

    TesteHorario teste_horario;
    cout << "HORÁRIO:" << endl << "    ";
    if (teste_horario.run() == TesteHorario::SUCESSO)
        cout << "Teste 'HORÁRIO' bem-sucedido" << endl;

    TesteNome teste_nome;
    cout << "NOME:" << endl << "    ";
    if (teste_nome.run() == TesteNome::SUCESSO)
        cout << "Teste 'NOME' bem-sucedido" << endl;

    TesteSenha teste_senha;
    cout << "SENHA:" << endl << "    ";
    if (teste_senha.run() == TesteSenha::SUCESSO)
        cout << "Teste 'SENHA' bem-sucedido" << endl;

    

}
