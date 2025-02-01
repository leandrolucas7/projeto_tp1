//232024572

/**
 * @file interfacesSer.hpp
 * @brief Declaração das interfaces da camada de serviços.
 *
 * Este arquivo contém a definição de interfaces utilizadas para manipulação de entidades
 * na camada de serviços do sistema. Essas interfaces fornecem métodos para criação, atualização
 * e remoção de diferentes tipos de dados.
 */

#ifndef INTERFACES_SER_HPP
#define INTERFACES_SER_HPP

#include "dominios/DOMINIOS.hpp"
#include "entidades/ENTIDADES.hpp"
#include "./container.hpp"

/**
 * @brief Declaração antecipada das interfaces de serviço.
 */
template <typename TipoAnterior, typename TipoAtual>
class IntSerCUD;
class IntSerCUDConta;
class IntSerCUDViagem;
class IntSerCUDDestino;
class IntSerCUDHospedagem;
class IntSerCUDAtividade;

/**
 * @brief Interface genérica para operações de criação, atualização e remoção.
 *
 * @tparam TipoAnterior Tipo associado ao nível superior da relação.
 * @tparam TipoAtual Tipo principal manipulado pela interface.
 */
template <typename TipoAnterior, typename TipoAtual>
class IntSerCUD
{
    public:
        virtual ~IntSerCUD() {}
        virtual void create(TipoAnterior*, TipoAtual*) = 0;
        virtual void update(TipoAtual*) = 0;
        virtual void destroy(TipoAnterior*, TipoAtual*) = 0;
};

/**
 * @brief Interface para gerenciamento de contas.
 *
 * Define métodos para operações essenciais sobre contas de usuário.
 */
class IntSerCUDConta
{
    public:
        virtual ~IntSerCUDConta() {}
        virtual bool create(Conta*, Codigo, Senha) = 0;
        virtual void update(Conta*, Senha) = 0;
        virtual void destroy(Conta*) = 0;
};

/**
 * @brief Interface para controle de viagens.
 *
 * Fornece métodos para criar, atualizar e excluir registros de viagens.
 */
class IntSerCUDViagem
{
    public:
        virtual ~IntSerCUDViagem() {}
        virtual bool create(Conta*, Codigo, Nome, Avaliacao) = 0;
        virtual void update(Viagem*, Nome, Avaliacao) = 0;
        virtual void destroy(Conta*, Viagem*) = 0;
};

/**
 * @brief Interface para gerenciamento de destinos.
 *
 * Permite manipular destinos dentro de uma viagem.
 */
class IntSerCUDDestino
{
    public:
        virtual ~IntSerCUDDestino() {}
        virtual bool create(Viagem*, Codigo, Nome, Data, Data, Avaliacao) = 0;
        virtual void update(Destino*, Nome, Data, Data, Avaliacao) = 0;
        virtual void destroy(Viagem*, Destino*) = 0;
};

/**
 * @brief Interface para administração de hospedagens.
 *
 * Define operações para gerenciar registros de hospedagem em um destino.
 */
class IntSerCUDHospedagem
{
    public:
        virtual ~IntSerCUDHospedagem() {}
        virtual bool create(Destino*, Codigo, Nome, Dinheiro, Avaliacao) = 0;
        virtual void update(Hospedagem*, Nome, Dinheiro, Avaliacao) = 0;
        virtual void destroy(Destino*, Hospedagem*) = 0;
};

/**
 * @brief Interface para controle de atividades.
 *
 * Fornece métodos para criação, atualização e exclusão de atividades associadas a um destino.
 */
class IntSerCUDAtividade
{
    public:
        virtual ~IntSerCUDAtividade() {}
        virtual bool create(Destino*, Codigo, Nome, Data, Horario, Duracao, Dinheiro, Avaliacao) = 0;
        virtual void update(Atividade*, Nome, Data, Horario, Duracao, Dinheiro, Avaliacao) = 0;
        virtual void destroy(Destino*, Atividade*) = 0;
};

#endif // INTERFACES_SER_HPP
