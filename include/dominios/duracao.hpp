#ifndef DURACAO_HPP
#define DURACAO_HPP

#include "super_dominio.hpp"

class Duracao : public SuperDominio<int>
{
    private:
        bool validar(int) override;
};

#endif
