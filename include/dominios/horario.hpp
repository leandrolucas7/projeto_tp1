#ifndef HORARIO_HPP
#define HORARIO_HPP

#include "super_dominio.hpp"
#include <string>
using namespace std;

class Horario : public SuperDominio<string>
{
    private:
        void validar(string) override;
};


#endif
