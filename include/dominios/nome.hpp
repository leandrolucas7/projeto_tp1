#ifndef NOME_HPP
#define NOME_HPP

#include "super_dominio.hpp"
#include <string>
using namespace std;

class Nome: public SuperDominio<string>
{
    private:
        void validar(string) override;
};


#endif