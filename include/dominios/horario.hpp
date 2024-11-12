#ifndef HORARIO_HPP
#define HORARIO_HPP


#include <string>
using namespace std;

class Horario
{
    private:
        string valor;
        bool validar(string);
    public:
        bool set_valor(string);
        // Precisam que o valor esteja definido
        string get_valor() const;
        int get_hora() const;
        int get_minutos() const;
};

inline string Horario::get_valor() const
{ return valor; }

#endif