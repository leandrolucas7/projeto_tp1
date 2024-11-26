#include <iostream>
#include <string>
#include "include/dominios/DOMINIOS.hpp"
#include "include/testes/TESTES.hpp"

using namespace std;
int main()
{
    TesteAvaliacao teste_avaliacao;
    cout << "AVALIAÇÃO:" << endl << "    ";
    if (teste_avaliacao.run() == TesteAvaliacao::SUCESSO)
        cout << "Teste 'AVALIAÇÃO' bem-sucedido" << endl;
}
