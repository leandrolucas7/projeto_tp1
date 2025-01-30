#ifndef controladoresApr_HPP
#define controladoresApr_HPP

#include "./interfacesApr.hpp"
#include "./interfacesSer.hpp"
#include "dominios/DOMINIOS.hpp"
#include "entidades/ENTIDADES.hpp"
#include <iostream>

class CntrAprInicial;
class CntrAprInput;
class CntrAprAutenticacao;
class CntrAprCRUDConta;
class CntrAprCRUDViagem;
class CntrAprCRUDDestino;
class CntrAprCRUDHospedagem;
class CntrAprCRUDAtividade;

class CntrAprInicial
{
    private:
        bool usuarioLogado;
        IntAprCRUDConta* cntrAprCRUDConta;
        IntAprAutenticacao* cntrAprAutenticacao;
    public:
        CntrAprInicial() {}
        void set_cntrAprCRUDConta(IntAprCRUDConta*);
        void set_cntrAprAutenticacao(IntAprAutenticacao*);
        void executar();
};


class CntrAprInput : public IntAprInput
{
    private:
        static CntrAprInput* instancia;
        CntrAprInput(){}
        ~CntrAprInput(){}
        CntrAprInput(const CntrAprInput&) = delete;
        CntrAprInput& operator=(const CntrAprInput&) = delete;
    public:
        static CntrAprInput* get_instancia();
        static void delete_instancia();
        void limpa_buffer() override;
        int get_user_input() override;
        Codigo get_codigo() override;
        Senha get_senha() override;
        Nome get_nome() override;
        Dinheiro get_diaria() override;
        Dinheiro get_preco() override;
        Duracao get_duracao() override;
        Horario get_horario() override;
        Avaliacao get_avaliacao() override;
        Data get_data_inicio() override;
        Data get_data_termino(Data) override;
        Data get_data_atividade(Data, Data) override;
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
        bool destroy(Conta*) override;
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
        bool destroy(Conta*,Viagem*) override;
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
        bool destroy(Viagem*,Destino*) override;
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
        bool destroy(Destino*,Hospedagem*) override;
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
        bool destroy(Destino*,Atividade*) override;
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
