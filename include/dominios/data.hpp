#ifndef DATA_HPP
#define DATA_HPP

#include "super_dominio.hpp"
#include <string>
using namespace std;

class Data : public SuperDominio<string>
{
    private:
        void validar(string) override;
};


#endif
