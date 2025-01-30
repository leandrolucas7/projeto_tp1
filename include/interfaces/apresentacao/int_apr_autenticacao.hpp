//232006215

/**
 * @file int_apr_autenticacao.hpp
 * @brief Interface para autenticação de usuários.
 *
 * Este arquivo contém a definição de uma interface responsável pelo processo de autenticação
 * de contas no sistema.
 */

#ifndef INT_APR_AUTENTICACAO_HPP
#define INT_APR_AUTENTICACAO_HPP

#include "../../entidades/conta.hpp"

/**
 * @brief Interface para autenticação.
 *
 * Define o método necessário para validar credenciais de uma conta.
 */
class IntAprAutenticacao
{
    public:
        /**
         * @brief Verifica a autenticidade das credenciais fornecidas.
         *
         * @param conta Ponteiro para a conta que deseja ser autenticada.
         * @return true se a autenticação for bem-sucedida, false caso contrário.
         */
        virtual bool autenticar(Conta*) = 0;
};

#endif // INT_APR_AUTENTICACAO_HPP
