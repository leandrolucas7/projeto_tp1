#include <iostream>
#include <stdexcept>
#include "include/dominios/DOMINIOS.hpp"
#include "include/entidades/ENTIDADES.hpp"
using namespace std;

int main()
{
    Duracao tempo;
    try 
    {
        tempo.set_valor(50);
        cout << tempo.get_valor() << endl;
    }
    catch(invalid_argument &exp)
    {
        cout << "Excecao: " << exp.what() << endl;
    }

    Duracao tempo2;
    try 
    {
        tempo2.set_valor(50000);
        cout << tempo2.get_valor() << endl;
    }
    catch(invalid_argument &exp)
    {
        cout << "Excecao: " << exp.what() << endl;
    }

    Horario hora;
    try 
    {
        hora.set_valor("20:45");
        cout << hora.get_valor() << endl;
    }
    catch(invalid_argument &exp)
    {
        cout << "Excecao: " << exp.what() << endl;
    }

    Horario hora2;
    try 
    {
        hora2.set_valor("25:00");
        cout << hora2.get_valor() << endl;
    }
    catch(invalid_argument &exp)
    {
        cout << "Excecao: " << exp.what() << endl;
    }
}
