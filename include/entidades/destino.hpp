// Matrícula: 232006832
/**
 * @file destino.hpp
 * @brief Declaração da classe 'Destino'.
 */

#ifndef DESTINO_HPP_INCLUDED
#define DESTINO_HPP_INCLUDED

#include "../dominios/DOMINIOS.hpp"

/**
 * @class Destino
 * @brief Classe que armazena informações relacionadas a viagens, como identificadores, datas e avaliações.
 * 
 * A classe armazena cinco atributos principais:
 * 
 * - Um código identificador do destino da viagem (`Codigo`);
 * - O nome do destino da viagem (`Nome`);
 * - Uma data para o início da viagem (`Data`);
 * - Uma data para o término da viagem (`Data`);
 * - Uma avaliação atribuída ao destino pelo usuário (`Avaliacao`).
 * 
 * Além disso, fornece métodos para definir e obter esses atributos.
 * 
 */

class Destino {
    private:
        Codigo codigo; ///< Código identificador do destino da viagem.
        Nome nome; ///< Nome do destino da viagem.
        Data data_inicio; ///< Data de início da viagem.
        Data data_termino; ///< Data de término da viagem.
        Avaliacao avaliacao; ///< Avaliação atribuída ao destino pelo usuário.
    public:
        /**
         * @brief Define o código de identificação do destino da viagem.
         * 
         * @param codigo Referência constante para um objeto do tipo `Codigo` representando o código identificador que será atribuído ao destino da viagem.
         */
        void set_codigo(const Codigo& codigo);
        /**
         * @brief Retorna o código identificador do destino da viagem.
         * 
         * @return Instância de 'Codigo' que representa o código indentificador do destino da viagem.
         */
        Codigo get_codigo() const;
        /**
         * @brief Define o nome do destino da viagem.
         * 
         * @param nome Referência constante para um objeto do tipo `Nome` representando o nome que será atribuído ao destino da viagem.
         */
        void set_nome(const Nome& nome);
        /**
         * @brief Retorna o nome do destino da viagem.
         * 
         * @return Instância de `Nome` que representa o nome do destino da viagem.
         */
        Nome get_nome() const;
        /**
         * @brief Define a data de início da viagem.
         * 
         *@param data_inicio Referência constante para um objeto do tipo `Data` representando a data que será atribuída ao início da viagem.
         */
        void set_data_inicio(const Data& data_inicio);
        /**
         * @brief Retorna a data de início da viagem.
         * 
         * @return Instância de `Data` que representa a data de início da viagem.
         */
        Data get_data_inicio() const;
        /**
         * @brief Define a data de término da viagem.
         * 
         *@param data_termino Referência constante para um objeto do tipo `Data` representando a data que será atribuída ao término da viagem.
         */
        void set_data_termino(const Data& data_termino);
        /**
         * @brief Retorna a data de término da viagem.
         * 
         * @return Instância de `Data` que representa a data de início da viagem.
         */
        Data get_data_termino() const;
        /**
         * @brief Define a avaliação atribuída ao destino pelo usuário.
         * 
         *@param avaliacao Referência constante para um objeto do tipo `Avaliacao` representando a avaliação que será atribuída ao destino pelo usuário.
         */       
        void set_avaliacao(const Avaliacao& avaliacao);
        /**
         * @brief Retorna a avaliação atribuída ao destino pelo usuário.
         * 
         * @return Instância de `Avaliacao` que representa a avaliação atribuída ao destino pelo usuário.
         */
        Avaliacao get_avaliacao() const;
};

// Implementação inline dos métodos

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
