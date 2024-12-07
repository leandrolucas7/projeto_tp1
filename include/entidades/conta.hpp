// Matrícula: 232024572
/**
 * @file conta.hpp
 * @brief Declaração da classe `Conta`.
 * 
 * Este arquivo define a classe `Conta`, que armazena informações de um usuário, como um código único de identificação e uma sequência de autenticação associada.
 * 
 */

#ifndef CONTA_HPP_INCLUDED
#define CONTA_HPP_INCLUDED

#include "../dominios/DOMINIOS.hpp"

/**
 * @brief Representa as informações de identificação e autenticação de um usuário no sistema.
 * 
 * A classe armazena dois atributos principais:
 * 
 * - Um código único de identificação (`Codigo`).
 * - Uma sequência de autenticação segura (`Senha`).
 * 
 * Além disso, fornece métodos para definir e obter esses atributos.
 * 
 */

class Conta 
{
    private:
        Codigo codigo; ///< Código único associado ao usuário.
        Senha senha;   ///< Sequência de autenticação segura do usuário.
    
    public:
        /**
         * @brief Define o código de identificação associado ao usuário.
         * 
         * @param codigo Instância de `Codigo` que será atribuída ao usuário.
         */
        void set_codigo(const Codigo& codigo);

        /**
         * @brief Retorna o código de identificação associado ao usuário.
         * 
         * @return Instância de `Codigo` que representa o código de identificação do usuário.
         */
        Codigo get_codigo() const;

        /**
         * @brief Define a sequência de autenticação associada ao usuário.
         * 
         * @param senha Instância de `Senha` que será atribuída ao usuário.
         */
        void set_senha(const Senha& senha);

        /**
         * @brief Retorna a sequência de autenticação associada ao usuário.
         * 
         * @return Instância de `Senha` que representa a sequência de autenticação do usuário.
         */
        Senha get_senha() const;
};

// Implementação inline dos métodos

inline void Conta::set_codigo(const Codigo& codigo)
{
    this->codigo = codigo;
}

inline Codigo Conta::get_codigo() const 
{
    return codigo;
}

inline void Conta::set_senha(const Senha& senha)
{
    this->senha = senha;
}

inline Senha Conta::get_senha() const 
{
    return senha;
}

#endif // CONTA_HPP_INCLUDED
