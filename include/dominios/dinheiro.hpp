#ifndef DINHEIRO_HPP
#define DINHEIRO_HPP

#include "super_dominio.hpp"
#include <string>
using namespace std;

class Dinheiro : public SuperDominio<double>
{
    private:
        void validar(double) override;
};


#endif
