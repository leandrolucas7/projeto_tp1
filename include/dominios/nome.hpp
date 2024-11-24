#ifndef NOME_HPP
#define NOME_HPP

#include <string>
using namespace std;

class Nome
{
    private:
        string valor;
        void validar(string);
    public:
        bool set_valor(string);
        string get_valor() const;
};

inline string Nome::get_valor() const
{ return valor; }

#endif
