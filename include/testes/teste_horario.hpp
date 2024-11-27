#ifndef TESTE_HORARIO_HPP
#define TESTE_HORARIO_HPP

#include <string>
#include "super_teste.hpp"

class TesteHorario : public SuperTeste<std::string>
{
    protected:
        void set_valores() override;
};

#endif
