#ifndef SUPER_DOMINIO_HPP
#define SUPER_DOMINIO_HPP

#include <iostream>
using namespace std;

class SuperDominio
{
    protected:
        string valor;
        virtual bool validar(string) = 0;
    public:
        bool set_valor(string);
        string get_valor() const;
};

inline string SuperDominio::get_valor() const
{ return this->valor; }

bool SuperDominio::set_valor(string valor)
{
    if (!validar(valor))
        return false;
    this->valor = valor;
    return true;
}

#endif