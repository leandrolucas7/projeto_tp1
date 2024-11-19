#ifndef AVALIACAO_HPP
#define AVALIACAO_HPP

#include <string>
using namespace std;

class Avaliacao
{
    private:
        int valor;
        void validar(int);
    public:
        bool set_valor(int);
        int get_valor() const;
};

inline int Avaliacao::get_valor() const
{ return valor; }

#endif
