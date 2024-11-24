#ifndef DINHEIRO_HPP
#define DINHEIRO_HPP

#include <string>
using namespace std;

class Dinheiro
{
    private:
        int valor;
        void validar(double);
    public:
        bool set_valor(double);
        double get_valor() const;
};

inline double Dinheiro::get_valor() const
{ return static_cast<double>(valor); }

#endif
