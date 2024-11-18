#include <iostream>
#include "include/dominios/DOMINIOS.hpp"
#include "include/entidades/ENTIDADES.hpp"

using namespace std;

int main()
{
    Dinheiro carteira;
    carteira.set_valor(500);
    cout << carteira.get_valor() << endl;

    Nome meu_nome;
    meu_nome.set_valor("ABC");
    cout << meu_nome.get_valor() << endl;

    cout << "MUDANÇA TESTE!" << endl;
}
