// Matrícula: 232024572
/**
 * @file conta.hpp
 * @brief Declaração da classe `Conta`.
 * 
 * Este arquivo define a classe `Conta`, que armazena informações de um usuário, como um código único e uma senha associada.
 * 
 */

#ifndef CONTA_HPP_INCLUDED
#define CONTA_HPP_INCLUDED

#include "../dominios/DOMINIOS.hpp"

/**
 * @brief Representa uma conta de usuário no sistema.
 * 
 * A classe armazena dois atributos principais:
 * 
 * - Um código único (`Codigo`).
 * - Uma senha segura (`Senha`).
 * 
 * Além disso, fornece métodos para definir e obter esses atributos.
 * 
 */

class Conta 
{
    private:
        Codigo codigo; ///< Código único associado à conta.
        Senha senha;   ///< Senha segura da conta.
    
    public:
        /**
         * @brief Define o código associado à conta.
         * 
         * @param codigo Instância de `Codigo` que será atribuída à conta.
         */
        void set_codigo(const Codigo& codigo);

        /**
         * @brief Retorna o código associado à conta.
         * 
         * @return Instância de `Codigo` que representa o código da conta.
         */
        Codigo get_codigo() const;

        /**
         * @brief Define a senha associada à conta.
         * 
         * @param senha Instância de `Senha` que será atribuída à conta.
         */
        void set_senha(const Senha& senha);

        /**
         * @brief Retorna a senha associada à conta.
         * 
         * @return Instância de `Senha` que representa a senha da conta.
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
