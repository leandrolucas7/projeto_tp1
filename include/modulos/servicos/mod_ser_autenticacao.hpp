#ifndef ModSerAutenticacao_HPP
#define ModSerAutenticacao_HPP

#include "../../interfaces/servicos/int_ser_autenticacao.hpp"

class ModSerAutenticacao : public IntSerAutenticacao
{
    public:
        bool autenticar(Conta) override;
};

#endif