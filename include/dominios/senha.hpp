#ifndef SENHA_HPP
#define SENHA_HPP

#include <string>
using namespace std;

class Senha
{
    private:
        string valor;
        void validar(string);
    public:
        bool set_valor(string);
        string get_valor() const;
};

inline string Senha::get_valor() const
{ return valor; }

#endif
