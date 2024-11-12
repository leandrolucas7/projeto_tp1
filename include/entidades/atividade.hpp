#ifndef ATIVIDADE_HPP_INCLUDED
#define ATIVIDADE_HPP_INCLUDED

#include "../dominios/DOMINIOS.hpp"

using namespace std;

class Atividade
{
    private:
        Codigo codigo;
        Nome nome;
        Data data;
        Horario horario;
        Duracao duracao;
        Dinheiro dinheiro;
        Avaliacao avaliacao;
    public:
        void set_codigo(const Codigo&);
        void set_nome(const Nome&);
        void set_data(const Data&);
        void set_horario(const Horario&);
        void set_duracao(const Duracao&);
        void set_dinheiro(const Dinheiro&);
        void set_avaliacao(const Avaliacao&);
        Codigo get_codigo() const;
        Nome get_nome() const;
        Data get_data() const;
        Horario get_horario() const;
        Duracao get_duracao() const;
        Dinheiro get_dinheiro() const;
        Avaliacao get_avaliacao() const;
};

inline void Atividade::set_codigo(const Codigo &codigo)
{
    this->codigo = codigo;
}

inline void Atividade::set_nome(const Nome &nome)
{
    this->nome = nome;
}

inline void Atividade::set_data(const Data &data)
{
    this->data = data;
}

inline void Atividade::set_horario(const Horario &horario)
{
    this->horario = horario;
}

inline void Atividade::set_duracao(const Duracao &duracao)
{
    this->duracao = duracao;
}

inline void Atividade::set_dinheiro(const Dinheiro &dinheiro)
{
    this->dinheiro = dinheiro;
}

inline void Atividade::set_avaliacao(const Avaliacao &avaliacao)
{
    this->avaliacao = avaliacao;
}

inline Codigo Atividade::get_codigo() const
{
    return codigo;
}

inline Nome Atividade::get_nome() const
{
    return nome;
}

inline Data Atividade::get_data() const
{
    return data;
}

inline Horario Atividade::get_horario() const
{
    return horario;
}

inline Duracao Atividade::get_duracao() const
{
    return duracao;
}

inline Dinheiro Atividade::get_dinheiro() const
{
    return dinheiro;
}

inline Avaliacao Atividade::get_avaliacao() const
{
    return avaliacao;
}

#endif
