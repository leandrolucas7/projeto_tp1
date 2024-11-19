#ifndef SENHA_HPP
#define SENHA_HPP

#include "super_dominio.hpp"
#include <string>

using namespace std;

class Senha : public SuperDominio<string> 
{
    private:
        bool validar(string);
};

#endif