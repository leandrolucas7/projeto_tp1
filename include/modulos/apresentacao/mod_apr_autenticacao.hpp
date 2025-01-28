#ifndef ModAprAutenticacao_HPP
#define ModAprAutenticacao_HPP

#include "../../interfaces/apresentacao/int_apr_autenticacao.hpp"

class ModAprAutenticacao : public IntAprAutenticacao
{
    public:
        bool autenticar(Conta*) override;
};

#endif