#ifndef controladoresSer_HPP
#define controladoresSer_HPP

#include "./interfacesApr.hpp"
#include "./interfacesSer.hpp"
#include "./stubs.hpp"
#include "dominios/DOMINIOS.hpp"
#include "entidades/ENTIDADES.hpp"
#include <iostream>

class CntrSerCUDConta : public IntSerCUDConta
{
    public:
        bool create(Conta*,Codigo,Senha) override;
        void update(Conta*,Senha) override;
        void destroy(Conta*) override;
};

class CntrSerCUDViagem : public IntSerCUDViagem
{
    public:
        void create(Conta*,Codigo,Nome,Avaliacao) override;
        void update(Viagem*,Nome,Avaliacao) override;
        void destroy(Conta*,Viagem*) override;
};

class CntrSerCUDDestino : public IntSerCUDDestino
{
    public:
        void create(Viagem*,Codigo,Nome,Data,Data,Avaliacao) override;
        void update(Destino*,Nome,Data,Data,Avaliacao) override;
        void destroy(Viagem*,Destino*) override;
};

class CntrSerCUDHospedagem: public IntSerCUDHospedagem
{
    public:
        void create(Destino*,Codigo,Nome,Dinheiro,Avaliacao) override;
        void update(Hospedagem*,Nome,Dinheiro,Avaliacao) override;
        void destroy(Destino*,Hospedagem*) override;
};

class CntrSerCUDAtividade : public IntSerCUDAtividade
{
    public:
        void create(Destino*,Codigo,Nome,Data,Horario,Duracao,Dinheiro,Avaliacao) override;
        void update(Atividade*,Nome,Data,Horario,Duracao,Dinheiro,Avaliacao) override;
        void destroy(Destino*,Atividade*) override;
};

#endif