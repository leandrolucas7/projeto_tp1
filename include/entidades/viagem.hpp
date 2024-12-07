#ifndef VIAGEM_HPP
#define VIAGEM_HPP

#include "../dominios/DOMINIOS.hpp"

class Viagem 
{
    private:
        Codigo codigo;
        Nome nome;
        Avaliacao avaliacao;
    public:
        void set_codigo(const Codigo&);
        Codigo get_codigo() const;

        void set_nome(const Nome&);
        Nome get_nome() const;

        void set_avaliacao(const Avaliacao&);
        Avaliacao get_avaliacao() const;
};

inline void Viagem::set_codigo(const Codigo &codigo) 
{
    this->codigo = codigo;
}

inline Codigo Viagem::get_codigo() const
{
    return codigo;
}

inline void Viagem::set_nome(const Nome &nome)
{
    this->nome = nome;
}

inline Nome Viagem::get_nome() const
{
    return nome;
}

inline void Viagem::set_avaliacao(const Avaliacao &avaliacao)
{
    this->avaliacao = avaliacao;
}

inline Avaliacao Viagem::get_avaliacao() const
{
    return avaliacao;
}


#endif
