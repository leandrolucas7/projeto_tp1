#ifndef AVALIACAO_HPP
#define AVALIACAO_HPP

#include "super_dominio.hpp"

class Avaliacao : public SuperDominio<int>
{
    private:
        void validar(int) override;
};

#endif
