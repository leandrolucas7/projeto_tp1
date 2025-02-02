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
#include <list>

class ContainerContas;
class ContainerViagens;
class ContainerDestinos;
class ContainerHospedagens;
class ContainerAtividades;



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
        list<Conta*> container;
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
        bool create(Conta*&);

        /**
         * @brief Remove uma conta do container.
         *
         * @param conta Referência para o ponteiro da conta a ser removida.
         */
        void destroy(Conta*&);

        /**
         * @brief Busca uma conta no container.
         *
         * @param conta Referência para o ponteiro da conta a ser buscada.
         * @return true se a conta foi encontrada, false caso contrário.
         */
        bool fetch(Conta*&);
};

class ContainerViagens
{
    private:
        static ContainerViagens* instancia;
        ContainerViagens() {}
        ~ContainerViagens();
        ContainerViagens(const ContainerViagens&) = delete;
        ContainerViagens& operator=(const ContainerViagens&) = delete;
        list<Viagem*> container;
    public:
        static ContainerViagens* get_instancia();
        static void delete_instancia();
        void create(Viagem*&);
        void destroy(Viagem*&);
        bool ja_existe(Codigo);
};

class ContainerDestinos
{
    private:
        static ContainerDestinos* instancia;
        ContainerDestinos() {}
        ~ContainerDestinos();
        ContainerDestinos(const ContainerDestinos&) = delete;
        ContainerDestinos& operator=(const ContainerDestinos&) = delete;
        list<Destino*> container;
    public:
        static ContainerDestinos* get_instancia();
        static void delete_instancia();
        void create(Destino*&);
        void destroy(Destino*&);
        bool ja_existe(Codigo);
};

class ContainerHospedagens
{
    private:
        static ContainerHospedagens* instancia;
        ContainerHospedagens() {}
        ~ContainerHospedagens();
        ContainerHospedagens(const ContainerHospedagens&) = delete;
        ContainerHospedagens& operator=(const ContainerHospedagens&) = delete;
        list<Hospedagem*> container;
    public:
        static ContainerHospedagens* get_instancia();
        static void delete_instancia();
        void create(Hospedagem*&);
        void destroy(Hospedagem*&);
        bool ja_existe(Codigo);
};

class ContainerAtividades
{
    private:
        static ContainerAtividades* instancia;
        ContainerAtividades() {}
        ~ContainerAtividades();
        ContainerAtividades(const ContainerAtividades&) = delete;
        ContainerAtividades& operator=(const ContainerAtividades&) = delete;
        list<Atividade*> container;
    public:
        static ContainerAtividades* get_instancia();
        static void delete_instancia();
        void create(Atividade*&);
        void destroy(Atividade*&);
        bool ja_existe(Codigo);
};

#endif // CONTAINER_HPP
