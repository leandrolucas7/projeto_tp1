//232024572

/**
 * @file int_apr_conta.hpp
 * @brief Interface para gerenciamento de contas.
 *
 * Este arquivo contém a definição de uma interface responsável pela criação e execução de ações
 * relacionadas a contas no sistema.
 */

#ifndef INT_APR_CONTA_HPP
#define INT_APR_CONTA_HPP

#include "../../entidades/conta.hpp"

/**
 * @brief Interface para operações com contas.
 *
 * Define métodos para criação e execução de processos associados a uma conta.
 */
class IntAprConta
{
    public:
        /**
         * @brief Cria uma nova conta.
         */
        void criar();

        /**
         * @brief Executa operações em uma conta existente.
         *
         * @param conta Objeto representando a conta a ser manipulada.
         */
        void executar(Conta);
};

#endif // INT_APR_CONTA_HPP
