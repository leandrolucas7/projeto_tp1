#ifndef interfacesSer_HPP
#define interfacesSer_HPP

#include "dominios/DOMINIOS.hpp"
#include "entidades/ENTIDADES.hpp"
#include "container.hpp"

template <typename TipoAnterior, typename TipoAtual>
class IntSerCUD
{
    public:
        virtual void create(TipoAnterior*,TipoAtual*) = 0;
        //virtual void read() = 0;
        virtual void update(TipoAtual*) = 0;
        virtual void destroy(TipoAnterior*, TipoAtual*) = 0;
};

class IntSerCUDConta
{
    public:
        virtual bool create(Conta*,Codigo,Senha) = 0;
        virtual void update(Conta*,Senha) = 0;
        virtual void destroy(Conta*) = 0;
};

class IntSerCUDViagem
{
    public:
        virtual void create(Conta*,Codigo,Nome,Avaliacao) = 0;
        virtual void update(Viagem*,Nome,Avaliacao) = 0;
        virtual void destroy(Conta*,Viagem*) = 0;
};

class IntSerCUDDestino
{
    public:
        virtual void create(Viagem*,Codigo,Nome,Data,Data,Avaliacao) = 0;
        virtual void update(Destino*,Nome,Data,Data,Avaliacao) = 0;
        virtual void destroy(Viagem*,Destino*) = 0;
};

class IntSerCUDHospedagem
{
    public:
        virtual void create(Destino*,Codigo,Nome,Dinheiro,Avaliacao) = 0;
        virtual void update(Hospedagem*,Nome,Dinheiro,Avaliacao) = 0;
        virtual void destroy(Destino*,Hospedagem*) = 0;
};


class IntSerCUDAtividade
{
    public:
        virtual void create(Destino*,Codigo,Nome,Data,Horario,Duracao,Dinheiro,Avaliacao) = 0;
        virtual void update(Atividade*,Nome,Data,Horario,Duracao,Dinheiro,Avaliacao) = 0;
        virtual void destroy(Destino*,Atividade*) = 0;
};





#endif