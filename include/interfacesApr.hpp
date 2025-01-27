#ifndef interfacesApr_HPP
#define interfacesApr_HPP

#include "dominios/DOMINIOS.hpp"
#include "entidades/ENTIDADES.hpp"

class IntAprCriarConta
{
    public:
        virtual void criar() = 0;
        //virtual void executar(Conta) = 0;
};
class IntAprEscolha
{
    public:
        virtual void escolher_entidade() = 0;
};


class IntAprAutenticacao
{
    public:
        virtual void set_cntrAprCRUDConta(IntAprCRUDConta*) = 0;
        virtual void autenticar(Conta*) = 0;
};



class IntAprCRUDConta
{
    public:
        virtual void set_cntrSerCUDConta(IntSerCUDConta*) = 0;
        virtual void set_cntrAprCRUDViagem(IntAprCRUDViagem*) = 0;
        virtual void create(Conta*) = 0;
        virtual void read(Conta*) = 0;
        virtual void update(Conta*) = 0;
        virtual bool destroy(Conta*) = 0;
};

template <typename T, typename U>
class IntAprCRUD
{
    public:
        virtual void create(T*) = 0;
        virtual void read(T*,U*) = 0;
        virtual void update(T*,U*) = 0;
        virtual bool destroy(T*,U*) = 0;
};

class IntAprCRUDViagem : public IntAprCRUD<Conta, Viagem>
{
    public:
        virtual void set_cntrSerCUDViagem(IntSerCUDViagem*) = 0;
        virtual void set_cntrAprCRUDDestino(IntAprCRUDDestino*) = 0;
        virtual void create(Conta*) = 0;
        virtual void read(Conta*,Viagem*) = 0;
        virtual void update(Conta*,Viagem*) = 0;
        virtual bool destroy(Conta*,Viagem*) = 0;
};

class IntAprCRUDDestino : public IntAprCRUD<Viagem, Destino>
{
    public:
        virtual void set_cntrSerCUDDestino(IntSerCUDDestino*) = 0;
        virtual void set_cntrAprCRUDHospedagem(IntAprCRUDHospedagem*) = 0;
        virtual void set_cntrAprCRUDAtividade(IntAprCRUDAtividade*) = 0;
        virtual void create(Viagem*) = 0;
        virtual void read(Viagem*,Destino*) = 0;
        virtual void update(Viagem*,Destino*) = 0;
        virtual bool destroy(Viagem*,Destino*) = 0;
};

class IntAprCRUDHospedagem : public IntAprCRUD<Destino, Hospedagem>
{
    public:
        virtual void set_cntrSerCUDHospedagem(IntSerCUDHospedagem*) = 0;
        virtual void create(Destino*) = 0;
        virtual void read(Destino*,Hospedagem*) = 0;
        virtual void update(Destino*,Hospedagem*) = 0;
        virtual bool destroy(Destino*,Hospedagem*) = 0;
};

class IntAprCRUDAtividade : public IntAprCRUD<Destino, Atividade>
{
    public:
        virtual void set_cntrSerCUDAtividade(IntSerCUDAtividade*) = 0;
        virtual void create(Destino*) = 0;
        virtual void read(Destino*,Atividade*) = 0;
        virtual void update(Destino*,Atividade*) = 0;
        virtual bool destroy(Destino*,Atividade*) = 0;
};




class IntSerAutenticacao
{
    public:
        virtual bool autenticar(Conta) = 0;
};

#endif