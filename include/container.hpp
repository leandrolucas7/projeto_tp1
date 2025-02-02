//222025852

//232006832

/**
 * @file container.hpp
 * @brief Definição dos containers para gerenciamento de contas, viagens, destinos, hospedagens e atividades.
 *
 * Este arquivo contém a definição de singletons responsáveis por armazenar, gerenciar e fornecer acesso aos dados do usuário os dados dentro do sistema.
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

        /**
         * @brief Lista que armazena ponteiros para objetos do tipo Conta.
         */
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

/**
 * @brief Classe singleton para gerenciamento de viagens.
 *
 * Armazena e gerencia viagens no sistema, garantindo acesso único ao container.
 */
class ContainerViagens
{
    private:
        static ContainerViagens* instancia; /**< Instância única da classe. */

        /**
         * @brief Construtor privado para implementação do singleton.
         */
        ContainerViagens() {}

         /**
         * @brief Destrutor da classe.
         */
        ~ContainerViagens();

        /**
         * @brief Deleta o construtor de cópia para evitar duplicações.
         */
        ContainerViagens(const ContainerViagens&) = delete;

        /**
         * @brief Deleta o operador de atribuição para evitar cópias.
         */
        ContainerViagens& operator=(const ContainerViagens&) = delete;

        /**
         * @brief Lista que armazena ponteiros para objetos do tipo Viagem.
         */
        list<Viagem*> container;
    public:
        /**
         * @brief Obtém a instância única do container.
         *
         * @return Ponteiro para a instância do container.
         */
        static ContainerViagens* get_instancia();

        /**
         * @brief Deleta a instância única do container.
         */
        static void delete_instancia();

        /**
         * @brief Adiciona uma viagem ao container.
         *
         * @param viagem Referência para o ponteiro da viagem a ser adicionada.
         */
        void create(Viagem*&);

        /**
         * @brief Remove uma viagem do container.
         *
         * @param viagem Referência para o ponteiro da viagem a ser removida.
         */
        void destroy(Viagem*&);

        /**
         * @brief Verifica se uma viagem de código especificado está no container.
         *
         * @param codigo Código da viagem a ser buscada.
         * @return true se a viagem com o código especificado foi encontrada ou false caso contrário.
         */
        bool ja_existe(Codigo);
};


/**
 * @brief Classe singleton para gerenciamento de destinos.
 *
 * Armazena e gerencia destinos no sistema, garantindo acesso único ao container.
 */
class ContainerDestinos
{
    private:
        static ContainerDestinos* instancia; /**< Instância única da classe. */

        /**
         * @brief Construtor privado para implementação do singleton.
         */
        ContainerDestinos() {}

        /**
         * @brief Destrutor da classe.
         */
        ~ContainerDestinos();

        /**
         * @brief Deleta o construtor de cópia para evitar duplicações.
         */
        ContainerDestinos(const ContainerDestinos&) = delete;

        /**
         * @brief Deleta o operador de atribuição para evitar cópias.
         */
        ContainerDestinos& operator=(const ContainerDestinos&) = delete;

        /**
         * @brief Lista que armazena ponteiros para objetos do tipo Destino.
         */
        list<Destino*> container;
    public:
        /**
         * @brief Obtém a instância única do container.
         *
         * @return Ponteiro para a instância do container.
         */
        static ContainerDestinos* get_instancia();

        /**
         * @brief Deleta a instância única do container.
         */
        static void delete_instancia();

        /**
         * @brief Adiciona um destino ao container.
         *
         * @param destino Referência para o ponteiro do destino a ser adicionado.
         */
        void create(Destino*&);

        /**
         * @brief Remove um destino do container.
         *
         * @param destino Referência para o ponteiro do destino a ser removido.
         */
        void destroy(Destino*&);

        /**
         * @brief Verifica se um destino de código especificado está no container.
         *
         * @param codigo Código do destino a ser buscado.
         * @return true se o destino com o código especificado foi encontrado ou false caso contrário.
         */
        bool ja_existe(Codigo);
};


/**
 * @brief Classe singleton para gerenciamento de hospedagens.
 *
 * Armazena e gerencia hospedagens no sistema, garantindo acesso único ao container.
 */
class ContainerHospedagens
{
    private:
        static ContainerHospedagens* instancia; /**< Instância única da classe. */

        /**
         * @brief Construtor privado para implementação do singleton.
         */
        ContainerHospedagens() {}

        /**
         * @brief Destrutor da classe.
         */
        ~ContainerHospedagens();

        /**
         * @brief Deleta o construtor de cópia para evitar duplicações.
         */
        ContainerHospedagens(const ContainerHospedagens&) = delete;

        /**
         * @brief Deleta o operador de atribuição para evitar cópias.
         */
        ContainerHospedagens& operator=(const ContainerHospedagens&) = delete;

        /**
         * @brief Lista que armazena ponteiros para objetos do tipo Hospedagem.
         */
        list<Hospedagem*> container;
    public:
        /**
         * @brief Obtém a instância única do container.
         *
         * @return Ponteiro para a instância do container.
         */
        static ContainerHospedagens* get_instancia();

        /**
         * @brief Deleta a instância única do container.
         */
        static void delete_instancia();

        /**
         * @brief Adiciona uma hospedagem ao container.
         *
         * @param hospedagem Referência para o ponteiro da hospedagem a ser adicionada.
         */
        void create(Hospedagem*&);

        /**
         * @brief Remove uma hospedagem do container.
         *
         * @param hospedagem Referência para o ponteiro da hospedagem a ser removida.
         */
        void destroy(Hospedagem*&);

        /**
         * @brief Verifica se uma hospedagem de código especificado está no container.
         *
         * @param codigo Código da hospedagem a ser buscada.
         * @return true se a hospedagem com o código especificado foi encontrada ou false caso contrário.
         */
        bool ja_existe(Codigo);
};


/**
 * @brief Classe singleton para gerenciamento de atividades.
 *
 * Armazena e gerencia atividades no sistema, garantindo acesso único ao container.
 */
class ContainerAtividades
{
    private:
        static ContainerAtividades* instancia; /**< Instância única da classe. */

        /**
         * @brief Construtor privado para implementação do singleton.
         */
        ContainerAtividades() {}

        /**
         * @brief Destrutor da classe.
         */
        ~ContainerAtividades();

        /**
         * @brief Deleta o construtor de cópia para evitar duplicações.
         */
        ContainerAtividades(const ContainerAtividades&) = delete;

        /**
         * @brief Deleta o operador de atribuição para evitar cópias.
         */
        ContainerAtividades& operator=(const ContainerAtividades&) = delete;

        /**
         * @brief Lista que armazena ponteiros para objetos do tipo Atividade.
         */
        list<Atividade*> container;
    public:
        /**
         * @brief Obtém a instância única do container.
         *
         * @return Ponteiro para a instância do container.
         */
        static ContainerAtividades* get_instancia();

        /**
         * @brief Deleta a instância única do container.
         */
        static void delete_instancia();

        /**
         * @brief Adiciona uma atividade ao container.
         *
         * @param atividade Referência para o ponteiro da atividade a ser adicionada.
         */
        void create(Atividade*&);

        /**
         * @brief Remove uma atividade do container.
         *
         * @param atividade Referência para o ponteiro da atividade a ser removida.
         */
        void destroy(Atividade*&);

        /**
         * @brief Verifica se uma atividade de código especificado está no container.
         *
         * @param codigo Código da atividade a ser buscada.
         * @return true se a atividade com o código especificado foi encontrada ou false caso contrário.
         */
        bool ja_existe(Codigo);
};

#endif // CONTAINER_HPP
