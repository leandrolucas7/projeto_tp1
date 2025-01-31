//232023969

#ifndef ModAprAutenticacao_HPP
#define ModAprAutenticacao_HPP

#include "../../interfaces/apresentacao/int_apr_autenticacao.hpp"

/**
 * @brief Módulo responsável pela autenticação de usuários no sistema
 * 
 * Esta classe implementa a interface IntAprAutenticacao e fornece
 * funcionalidade para autenticar usuários através de suas contas.
 */
class ModAprAutenticacao : public IntAprAutenticacao
{
    public:
        /**
         * @brief Realiza a autenticação de um usuário
         * 
         * @param conta Ponteiro para objeto Conta contendo as credenciais do usuário
         * @return true Se a autenticação for bem-sucedida
         * @return false Se a autenticação falhar
         */
        bool autenticar(Conta*) override;
};

#endif // MOD_APR_AUTENTICACAO_HPP
