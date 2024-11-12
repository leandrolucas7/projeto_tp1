#ifndef HOSPEDAGEM_HPP
#define HOSPEDAGEM_HPP

#include "../dominios/DOMINIOS.hpp"

class Hospedagem 
{
    private:
        Codigo codigo;
        Nome nome;
        Dinheiro diaria;
        Avaliacao avaliacao;
    public:
        void set_codigo(const Codigo&);
        Codigo get_codigo() const;

        void set_nome(const Nome&);
        Nome get_nome() const;

        void set_diaria(const Dinheiro&);
        Dinheiro get_diaria() const;

        void set_avaliacao(const Avaliacao&);
        Avaliacao get_avaliacao() const;
};

inline void Hospedagem::set_codigo(const Codigo &codigo) 
{
    this->codigo = codigo;
}

inline Codigo Hospedagem::get_codigo() const
{
    return codigo;
}

inline void Hospedagem::set_nome(const Nome &nome)
{
    this->nome = nome;
}

inline Nome Hospedagem::get_nome() const
{
    return nome;
}

inline void Hospedagem::set_diaria(const Dinheiro &diaria)
{
    this->diaria = diaria;
}

inline Dinheiro Hospedagem::get_diaria() const
{
    return diaria;
}

inline void Hospedagem::set_avaliacao(const Avaliacao &avaliacao)
{
    this->avaliacao = avaliacao;
}

inline Avaliacao Hospedagem::get_avaliacao() const
{
    return avaliacao;
}

#endif