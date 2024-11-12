#ifndef DATA_HPP
#define DATA_HPP

#include <string>
using namespace std;

class Data 
{
    private:
        string valor;
        bool validar(string);

    public:
        bool set_valor(string);
        string get_valor() const;
};

inline string Data::get_valor() const 
{ return valor; }

#endif