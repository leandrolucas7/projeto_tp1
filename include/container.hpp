//222025852

/**
 * @file container.hpp
 * @brief Definição do container de contas.
 *
 * Este arquivo contém a implementação de um singleton responsável por armazenar e gerenciar
 * as contas dentro do sistema.
 */

#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include "./interfacesApr.hpp"
#include "./interfacesSer.hpp"
#include "dominios/DOMINIOS.hpp"
#include "entidades/ENTIDADES.hpp"

#include <vector>

/**
 * @brief Classe singleton para gerenciamento de contas.
 *
 * Armazena e gerencia contas no sistema, garantindo acesso único ao container.
 */
class ContainerContas
{
    private:
        static ContainerContas* instancia; /**< Instância única da classe. */
        std::vector<Conta*> contas; /**< Lista de contas armazenadas. */

        /**
         * @brief Construtor privado para implementação do singleton.
         */
        ContainerContas() {}

        /**
         * @brief Destrutor da classe.
         */
        ~ContainerContas();

        /**
         * @brief Deleta o construtor de cópia para evitar duplicações.
         */
        ContainerContas(const ContainerContas&) = delete;

        /**
         * @brief Deleta o operador de atribuição para evitar cópias.
         */
        ContainerContas& operator=(const ContainerContas&) = delete;

    public:
        /**
         * @brief Obtém a instância única do container.
         *
         * @return Ponteiro para a instância do container.
         */
        static ContainerContas* get_instancia();

        /**
         * @brief Deleta a instância única do container.
         */
        static void delete_instancia();

        /**
         * @brief Adiciona uma conta ao container.
         *
         * @param conta Referência para o ponteiro da conta a ser adicionada.
         * @return true se a conta foi adicionada com sucesso, false caso contrário.
         */
        bool add_conta(Conta*&);

        /**
         * @brief Remove uma conta do container.
         *
         * @param conta Referência para o ponteiro da conta a ser removida.
         */
        void remove_conta(Conta*&);

        /**
         * @brief Busca uma conta no container.
         *
         * @param conta Referência para o ponteiro da conta a ser buscada.
         * @return true se a conta foi encontrada, false caso contrário.
         */
        bool fetch_conta(Conta*&);
};

#endif // CONTAINER_HPP
