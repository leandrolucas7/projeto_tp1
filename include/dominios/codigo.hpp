#ifndef CODIGO_HPP
#define CODIGO_HPP

#include <string>
using namespace std;

class Codigo
{
    private:
        string valor;
        void validar(string);
    public:
        bool set_valor(string);
        string get_valor() const;
};

inline string Codigo::get_valor() const
{ return valor; }


#endif
