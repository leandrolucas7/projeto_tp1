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
        void create(ContainerContas*,Conta*,Codigo,Senha) override;
        void update(Conta*,Codigo,Senha) override;
        void destroy(ContainerContas*,Conta*) override;
};

class CntrSerCUDViagem : IntSerCUDViagem
{
    public:
        void create(Conta*,Codigo,Nome,Avaliacao) override;
        void update(Viagem*,Nome,Avaliacao) override;
        void destroy(Conta*,Viagem*) override;
};

class CntrSerCUDDestino : IntSerCUDDestino
{
    public:
        void create(Viagem*,Codigo,Nome,Data,Data,Avaliacao) override;
        void update(Destino*,Nome,Data,Data,Avaliacao) override;
        void destroy(Viagem*,Destino*) override;
};

class CntrSerCUDHospedagem: IntSerCUDHospedagem
{
    public:
        void create(Destino*,Codigo,Nome,Dinheiro,Avaliacao) override;
        void update(Hospedagem*,Nome,Dinheiro,Avaliacao) override;
        void destroy(Destino*,Hospedagem*) override;
};

class CntrSerCUDAtividade : IntSerCUDAtividade
{
    public:
        void create(Destino*,Codigo,Nome,Data,Horario,Duracao,Dinheiro,Avaliacao) override;
        void update(Atividade*,Nome,Data,Horario,Duracao,Dinheiro,Avaliacao) override;
        void destroy(Destino*,Atividade*) override;
};

#endif