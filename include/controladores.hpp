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

class CntrAprCRUDConta : public IntAprCRUDConta
{
    public:
        void create(Conta*) override;
        void read(Conta*) override;
        void update(Conta*) override;
        void destroy(Conta*) override;
};

class CntrAprCRUDViagem : public IntAprCRUD<Conta, Viagem>
{
    public:
        CntrAprCRUDViagem();
        void create(Conta*) override;
        void read(Conta*,Viagem*) override;
        void update(Conta*,Viagem*) override;
        void destroy(Conta*,Viagem*) override;
};

class CntrAprCRUDDestino : public IntAprCRUD<Viagem, Destino>
{
    public:
        CntrAprCRUDDestino();
        void create(Viagem*) override;
        void read(Viagem*,Destino*) override;
        void update(Viagem*,Destino*) override;
        void destroy(Viagem*,Destino*) override;
};

class CntrAprCRUDHospedagem : public IntAprCRUD<Destino, Hospedagem>
{
    public:
        CntrAprCRUDHospedagem();
        void create(Destino*) override;
        void read(Destino*,Hospedagem*) override;
        void update(Destino*,Hospedagem*) override;
        void destroy(Destino*,Hospedagem*) override;
};

class CntrAprCRUDAtividade : public IntAprCRUD<Destino, Atividade>
{
    public:
        CntrAprCRUDAtividade();
        void create(Destino*) override;
        void read(Destino*,Atividade*) override;
        void update(Destino*,Atividade*) override;
        void destroy(Destino*,Atividade*) override;
};


class CntrSerAutenticacao : public IntSerAutenticacao
{
    public:
        bool autenticar(Conta) override;
};

#endif