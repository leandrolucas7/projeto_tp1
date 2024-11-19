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

    Duracao tempo;
    tempo.set_valor(50);
    cout << tempo.get_valor() << endl;

    Horario hora;
    hora.set_valor("20:45");
    cout << hora.get_valor() << endl;

    Senha numero;
    numero.set_valor("48956");
    cout << numero.get_valor() << endl;

}
