// Matrícula: 2320013004
/**
 * @file viagem.hpp
 * @brief Declaração da classe 'Viagem'.
 */

#ifndef VIAGEM_HPP
#define VIAGEM_HPP

#include "../dominios/DOMINIOS.hpp"

/**
 * @class Viagem
 * @brief Representa uma viagem com informações como código, nome e avaliação.
 *
 * A classe armazena três atributos sendo eles:
 * - Código identificador da viagem;
 * - Nome da viagem;
 * - Avaliação de 0 a 5;
 * 
 * Além disso, a classe também tem métodos para armazenar e obter esses atributos.
 * 
 * `Codigo`, `Nome` e `Avaliacao`, definidos no arquivo `DOMINIOS.hpp`.
 */
class Viagem 
{
    private:
        Codigo codigo; /**< Código identificador da viagem. */
        Nome nome; /**< Nome associado à viagem. */
        Avaliacao avaliacao; /**< Avaliação da viagem. */

    public:
        /**
         * @brief Define o código da viagem.
         * @param codigo Objeto do tipo `Codigo` a ser atribuído.
         */
        void set_codigo(const Codigo&);

        /**
         * @brief Obtém o código da viagem.
         * @return Objeto do tipo `Codigo` correspondente ao código da viagem.
         */
        Codigo get_codigo() const;

        /**
         * @brief Define o nome da viagem.
         * @param nome Objeto do tipo `Nome` a ser atribuído.
         */
        void set_nome(const Nome&);

        /**
         * @brief Obtém o nome da viagem.
         * @return Objeto do tipo `Nome` correspondente ao nome da viagem.
         */
        Nome get_nome() const;

        /**
         * @brief Define a avaliação da viagem.
         * @param avaliacao Objeto do tipo `Avaliacao` a ser atribuído.
         */
        void set_avaliacao(const Avaliacao&);

        /**
         * @brief Obtém a avaliação da viagem.
         * @return Objeto do tipo `Avaliacao` correspondente à avaliação da viagem.
         */
        Avaliacao get_avaliacao() const;
};

/**
 * @brief Implementação inline dos métodos da classe `Viagem`.
**/
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
