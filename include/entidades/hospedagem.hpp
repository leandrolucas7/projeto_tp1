// Matrícula: 232023969
/**
 * @file hospedagem.hpp
 * @brief Declaração da classe `Hospedagem`.
 * 
 * Este arquivo define a classe Hospedagem, que armazena informações de uma reserva, como um código único de identificação e uma sequência de autenticação associada.
 * 
 */

#ifndef HOSPEDAGEM_HPP
#define HOSPEDAGEM_HPP

#include "../dominios/DOMINIOS.hpp"

/**
 * @brief Representa as informações de identificação e autenticação de uma reserva no sistema.
 * 
 * A classe armazena quatro atributos principais:
 * 
 * - Um código único de identificação (`Codigo`).
 * - Um texto de identificação de usuário (`Nome`).
 * - Um valor que informa o custo da diária (`Dinheiro`).
 * - Uma análise sobre a qualidade e características de um local (`Avaliação`).
 * 
 * Além disso, fornece métodos para definir e obter esses atributos.
 * 
 */

class Hospedagem 
{
    private:
        Codigo codigo; ///< Código único associado ao usuário.
        Nome nome; ///< Texto de identificação de usuário.
        Dinheiro diaria; ///< Valor que informa o custo da diária.
        Avaliacao avaliacao; ///< Análise sobre a qualidade e características do local.
    
public:
        /**
         * @brief Define o código de identificação associado ao usuário.
         * 
         * @param codigo Instância de `Codigo` que será atribuída ao usuário.
         */
        void set_codigo(const Codigo&);

        /**
         * @brief Retorna o código de identificação associado ao usuário.
         * 
         * @return Instância de `Codigo` que representa o código de identificação do usuário.
         */
        Codigo get_codigo() const;

        /**
         * @brief Define o texto de identificação associada ao usuário.
         * 
         * @param nome Instância de `Nome` que será atribuída ao usuário.
         */
        void set_nome(const Nome&);

        /**
         * @brief Retorna o texto de identificação associado ao usuário.
         * 
         * @return Instância de `Nome` que representa o texto de identificação associado ao usuário.
         */
        Nome get_nome() const;

        /**
         * @brief Define o valor que informa o custo da diária.
         * 
         * @param diaria Instância de `Dinheiro` que será atribuída ao valor.
         */
        void set_diaria(const Dinheiro&);

        /**
         * @brief Retorna o valor que informa o custo da diária.
         * 
         * @return Instância de `Dinheiro` que representa o custo da diária.
         */
        Dinheiro get_diaria() const;

        /**
         * @brief Define a análise sobre a qualidade e características de um local.
         * 
         * @param avaliacao Instância de `Avaliacao` que será atribuída ao local.
         */
        void set_avaliacao(const Avaliacao&);

        /**
         * @brief Retorna a análise sobre a qualidade e características de um local.
         * 
         * @return Instância de `Avaliação` que representa a análise sobre a qualidade e características de um local.
         */
        Avaliacao get_avaliacao() const;
};

// Implementação inline dos métodos

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

#endif // HOSPEDAGEM_HPP_INCLUDED
