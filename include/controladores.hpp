#ifndef controladores_HPP
#define controladores_HPP

#include "./interfaces.hpp"
#include "./commands.hpp"
#include "./stubs.hpp"
#include "dominios/DOMINIOS.hpp"
#include "entidades/ENTIDADES.hpp"
#include <iostream>

class CntrAprInicial
{
    private:
        bool usuarioLogado;
        IntAprCriarConta* cntrAprCriarConta;
        IntAprAutenticacao* cntrAprAutenticacao;
        IntAprEscolha* cntrAprEscolha;
    public:
        CntrAprInicial();
        void executar();
};



class CntrAprAutenticacao : public IntAprAutenticacao
{
    public:
        bool autenticar(Conta*) override;
};



class CntrSerAutenticacao : public IntSerAutenticacao
{
    public:
        bool autenticar(Conta) override;
};

#endif