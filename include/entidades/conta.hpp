// Matrícula: 232024572
/**
 * @file conta.hpp
 * @brief Declaração da classe `Conta`.
 * 
 * Esse arquivo define a classe 'Conta', que representa uma conta de usuário com informações de código e uma senha associada.
 * 
 */

#ifndef CONTA_HPP_INCLUDED
#define CONTA_HPP_INCLUDED

#include "../dominios/DOMINIOS.hpp"

/**
 * @class Conta
 * @brief Representa uma conta de usuário no sistema.
 * 
 * A classe armazena os dados de uma conta:
 * 
 * - Um código único ('Codigo').
 * - Uma senha segura ('Senha').
 * 
 * Esta classe fornece métodos para definir e obter os valoresdocódigo e da senha.
 * 
 */

class Conta 
{
    private:
        Codigo codigo; ///< Código único associado à conta.
        Senha senha;   ///< Senha segura da conta.
    
    public:
        /**
         * @brief Define o código da conta.
         * 
         * @param codigo Instância da classe `Codigo` representando o código único.
         */
        void set_codigo(const Codigo& codigo);

        /**
         * @brief Retorna o código da conta.
         * 
         * @return Instância da classe `Codigo` representando o código único da conta.
         */
        Codigo get_codigo() const;

        /**
         * @brief Define a senha da conta.
         * 
         * @param senha Instância da classe `Senha` representando a senha da conta.
         */
        void set_senha(const Senha& senha);

        /**
         * @brief Retorna a senha da conta.
         * 
         * @return Instância da classe `Senha` representando a senha da conta.
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
