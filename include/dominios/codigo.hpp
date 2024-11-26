#ifndef CODIGO_HPP
#define CODIGO_HPP

#include "super_dominio.hpp"
#include <string>
using namespace std;

class Codigo: public SuperDominio<string>
{
    private:
        void validar(string) override;
};


#endif
