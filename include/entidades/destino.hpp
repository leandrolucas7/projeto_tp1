#ifndef DESTINO_HPP_INCLUDED
#define DESTINO_HPP_INCLUDED

#include "../dominios/DOMINIOS.hpp"

class Destino {
    private:
        Codigo codigo;
        Nome nome;
        Data data_inicio;
        Data data_termino;
        Avaliacao avaliacao;
    public:
        void set_codigo(const Codigo&);
        Codigo get_codigo() const;
        void set_nome(const Nome&);
        Nome get_nome() const;
        void set_data_inicio(const Data&);
        Data get_data_inicio() const;
        void set_data_termino(const Data&);
        Data get_data_termino() const;
        void set_avaliacao(const Avaliacao&);
        Avaliacao get_avaliacao() const;
};

inline void Destino::set_codigo(const Codigo &codigo)
{ this->codigo = codigo; }

inline Codigo Destino::get_codigo() const
{ return codigo; }

inline void Destino::set_nome(const Nome &nome)
{ this->nome = nome; }

inline Nome Destino::get_nome() const
{ return nome; }

inline void Destino::set_data_inicio(const Data &data_inicio)
{ this->data_inicio = data_inicio; }

inline Data Destino::get_data_inicio() const
{ return data_inicio; }

inline void Destino::set_data_termino(const Data &data_termino)
{ this->data_termino = data_termino; }

inline Data Destino::get_data_termino() const
{ return data_termino; }

inline void Destino::set_avaliacao(const Avaliacao &avaliacao)
{ this->avaliacao = avaliacao; }

inline Avaliacao Destino::get_avaliacao() const
{ return avaliacao; }

#endif
