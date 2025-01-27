#ifndef controladoresApr_HPP
#define controladoresApr_HPP

#include "./interfacesApr.hpp"
#include "./interfacesSer.hpp"
#include "./stubs.hpp"
#include "dominios/DOMINIOS.hpp"
#include "entidades/ENTIDADES.hpp"
#include <iostream>

class CntrAprInicial
{
    private:
        bool usuarioLogado;
        IntAprCRUDConta* cntrAprCRUDConta;
        IntAprAutenticacao* cntrAprAutenticacao;
    public:
        void set_cntrAprCRUDConta(IntAprCRUDConta*);
        void set_cntrAprAutenticacao(IntAprAutenticacao*);
        CntrAprInicial();
        void executar();
};



class CntrAprAutenticacao : public IntAprAutenticacao
{
    private:
        IntAprCRUDConta* cntrAprCRUDConta;
    public:
        void set_cntrAprCRUDConta(IntAprCRUDConta*) override;
        void autenticar(Conta*) override;
};

class CntrAprCRUDConta : public IntAprCRUDConta
{
    private:
        IntSerCUDConta* cntrSerCUDConta;
        IntAprCRUDViagem* cntrAprCRUDViagem;
    public:
        void set_cntrSerCUDConta(IntSerCUDConta*) override;
        void set_cntrAprCRUDViagem(IntAprCRUDViagem*) override;
        void create(Conta*) override;
        void read(Conta*) override;
        void update(Conta*) override;
        void destroy(Conta*) override;
};

class CntrAprCRUDViagem : public IntAprCRUDViagem
{
    private:
        IntSerCUDViagem* cntrSerCUDViagem;
        IntAprCRUDDestino* cntrAprCRUDDestino;
    public:
        void set_cntrSerCUDViagem(IntSerCUDViagem*) override;
        void set_cntrAprCRUDDestino(IntAprCRUDDestino*) override;
        void create(Conta*) override;
        void read(Conta*,Viagem*) override;
        void update(Conta*,Viagem*) override;
        void destroy(Conta*,Viagem*) override;
};

class CntrAprCRUDDestino : public IntAprCRUDDestino
{
    private:
        IntSerCUDDestino* cntrSerCUDDestino;
        IntAprCRUDHospedagem* cntrAprCRUDHospedagem;
        IntAprCRUDAtividade* cntrAprCRUDAtividade;
    public:
        void set_cntrSerCUDDestino(IntSerCUDDestino*) override;
        void set_cntrAprCRUDHospedagem(IntAprCRUDHospedagem*) override;
        void set_cntrAprCRUDAtividade(IntAprCRUDAtividade*) override;
        void create(Viagem*) override;
        void read(Viagem*,Destino*) override;
        void update(Viagem*,Destino*) override;
        void destroy(Viagem*,Destino*) override;
};

class CntrAprCRUDHospedagem : public IntAprCRUDHospedagem
{
    private:
        IntSerCUDHospedagem* cntrSerCUDHospedagem;
    public:
        void set_cntrSerCUDHospedagem(IntSerCUDHospedagem*) override;
        void create(Destino*) override;
        void read(Destino*,Hospedagem*) override;
        void update(Destino*,Hospedagem*) override;
        void destroy(Destino*,Hospedagem*) override;
};

class CntrAprCRUDAtividade : public IntAprCRUDAtividade
{
    private:
        IntSerCUDAtividade* cntrSerCUDAtividade;
    public:
        void set_cntrSerCUDAtividade(IntSerCUDAtividade*);
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


inline void CntrAprInicial::set_cntrAprCRUDConta(IntAprCRUDConta* ptr)
{
    cntrAprCRUDConta = ptr;
}

inline void CntrAprInicial::set_cntrAprAutenticacao(IntAprAutenticacao* ptr)
{
    cntrAprAutenticacao = ptr;
}

inline void CntrAprAutenticacao::set_cntrAprCRUDConta(IntAprCRUDConta* ptr)
{
    cntrAprCRUDConta = ptr;
}


inline void CntrAprCRUDConta::set_cntrSerCUDConta(IntSerCUDConta* ptr)
{
    cntrSerCUDConta = ptr;
}

inline void CntrAprCRUDConta::set_cntrAprCRUDViagem(IntAprCRUDViagem* ptr)
{
    cntrAprCRUDViagem = ptr;
}

inline void CntrAprCRUDViagem::set_cntrSerCUDViagem(IntSerCUDViagem* ptr)
{
    cntrSerCUDViagem = ptr;
}

inline void CntrAprCRUDViagem::set_cntrAprCRUDDestino(IntAprCRUDDestino* ptr)
{
    cntrAprCRUDDestino = ptr;
}

inline void CntrAprCRUDDestino::set_cntrSerCUDDestino(IntSerCUDDestino* ptr)
{
    cntrSerCUDDestino = ptr;
}

inline void CntrAprCRUDDestino::set_cntrAprCRUDHospedagem(IntAprCRUDHospedagem* ptr)
{
    cntrAprCRUDHospedagem = ptr;
}

inline void CntrAprCRUDDestino::set_cntrAprCRUDAtividade(IntAprCRUDAtividade* ptr)
{
    cntrAprCRUDAtividade = ptr;
}

inline void CntrAprCRUDHospedagem::set_cntrSerCUDHospedagem(IntSerCUDHospedagem* ptr)
{
    cntrSerCUDHospedagem = ptr;
}

inline void CntrAprCRUDAtividade::set_cntrSerCUDAtividade(IntSerCUDAtividade* ptr)
{
    cntrSerCUDAtividade = ptr;
}

#endif