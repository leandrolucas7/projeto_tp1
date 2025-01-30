//23202472

/**
 * @file IntSerAutenticacao.hpp
 * @brief Interface para autenticação de contas no serviço.
 *
 * Este arquivo define a interface responsável por validar credenciais de uma conta
 * na camada de serviços do sistema.
 */

#ifndef INT_SER_AUTENTICACAO_HPP
#define INT_SER_AUTENTICACAO_HPP

#include "../../entidades/conta.hpp"

/**
 * @brief Interface para autenticação de contas.
 *
 * Define um método abstrato para verificar a autenticidade de uma conta.
 */
class IntSerAutenticacao
{
    public:
        /**
         * @brief Valida as credenciais de uma conta.
         *
         * @param conta Objeto representando a conta a ser autenticada.
         * @return true se a autenticação for bem-sucedida, false caso contrário.
         */
        virtual bool autenticar(Conta) = 0;
};

#endif // INT_SER_AUTENTICACAO_HPP
