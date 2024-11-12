#ifndef DURACAO_HPP
#define DURACAO_HPP


#include <string>
using namespace std;

class Duracao
{
    private:
        int valor;
        bool validar(int);
    public:
        bool set_valor(int);
        int get_valor() const;
};

inline int Duracao::get_valor() const
{ return valor; }

#endif