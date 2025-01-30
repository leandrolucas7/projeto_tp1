//232023969

/**
 * @file controladoresSer.HPP
 * @brief Define as classes controladoras de serviço para operações CRUD
 * @details Este arquivo contém as declarações das classes controladoras que gerenciam
 *          as operações Create, Read, Update e Delete para as entidades do sistema
 */

#ifndef controladoresSer_HPP
#define controladoresSer_HPP

#include "./interfacesApr.hpp"
#include "./interfacesSer.hpp"
#include "dominios/DOMINIOS.hpp"
#include "entidades/ENTIDADES.hpp"
#include <iostream>

// Declarações antecipadas das classes
class CntrSerCUDConta;
class CntrSerCUDViagem;
class CntrSerCUDDestino;
class CntrSerCUDHospedagem;
class CntrSerCUDAtividade;

/**
 * @class CntrSerCUDConta
 * @brief Controlador de serviço para gerenciamento de contas
 * @details Implementa operações CRUD para entidades do tipo Conta
 */
class CntrSerCUDConta : public IntSerCUDConta {
    public:
        /**
         * @brief Cria uma nova conta
         * @param conta Ponteiro para o objeto Conta
         * @param codigo Código da conta
         * @param senha Senha da conta
         * @return true se a criação for bem-sucedida, false caso contrário
         */
        bool create(Conta* conta, Codigo codigo, Senha senha) override;

        /**
         * @brief Atualiza uma conta existente
         * @param conta Ponteiro para o objeto Conta
         * @param senha Nova senha da conta
         */
        void update(Conta* conta, Senha senha) override;

        /**
         * @brief Remove uma conta
         * @param conta Ponteiro para o objeto Conta a ser removido
         */
        void destroy(Conta* conta) override;
};

/**
 * @class CntrSerCUDViagem
 * @brief Controlador de serviço para gerenciamento de viagens
 * @details Implementa operações CRUD para entidades do tipo Viagem
 */
class CntrSerCUDViagem : public IntSerCUDViagem {
    public:
        /**
         * @brief Cria uma nova viagem
         * @param conta Ponteiro para a conta associada
         * @param codigo Código da viagem
         * @param nome Nome da viagem
         * @param avaliacao Avaliação da viagem
         * @return true se a criação for bem-sucedida, false caso contrário
         */
        bool create(Conta* conta, Codigo codigo, Nome nome, Avaliacao avaliacao) override;

        /**
         * @brief Atualiza uma viagem existente
         * @param viagem Ponteiro para o objeto Viagem
         * @param nome Novo nome da viagem
         * @param avaliacao Nova avaliação da viagem
         */
        void update(Viagem* viagem, Nome nome, Avaliacao avaliacao) override;

        /**
         * @brief Remove uma viagem
         * @param conta Ponteiro para a conta associada
         * @param viagem Ponteiro para o objeto Viagem a ser removido
         */
        void destroy(Conta* conta, Viagem* viagem) override;
};

/**
 * @class CntrSerCUDDestino
 * @brief Controlador de serviço para gerenciamento de destinos
 * @details Implementa operações CRUD para entidades do tipo Destino
 */
class CntrSerCUDDestino : public IntSerCUDDestino {
    public:
        /**
         * @brief Cria um novo destino
         * @param viagem Ponteiro para a viagem associada
         * @param codigo Código do destino
         * @param nome Nome do destino
         * @param dataInicio Data de início
         * @param dataTermino Data de término
         * @param avaliacao Avaliação do destino
         * @return true se a criação for bem-sucedida, false caso contrário
         */
        bool create(Viagem* viagem, Codigo codigo, Nome nome, Data dataInicio, Data dataTermino, Avaliacao avaliacao) override;

        /**
         * @brief Atualiza um destino existente
         * @param destino Ponteiro para o objeto Destino
         * @param nome Novo nome do destino
         * @param dataInicio Nova data de início
         * @param dataTermino Nova data de término
         * @param avaliacao Nova avaliação do destino
         */
        void update(Destino* destino, Nome nome, Data dataInicio, Data dataTermino, Avaliacao avaliacao) override;

        /**
         * @brief Remove um destino
         * @param viagem Ponteiro para a viagem associada
         * @param destino Ponteiro para o objeto Destino a ser removido
         */
        void destroy(Viagem* viagem, Destino* destino) override;
};

/**
 * @class CntrSerCUDHospedagem
 * @brief Controlador de serviço para gerenciamento de hospedagens
 * @details Implementa operações CRUD para entidades do tipo Hospedagem
 */
class CntrSerCUDHospedagem: public IntSerCUDHospedagem {
    public:
        /**
         * @brief Cria uma nova hospedagem
         * @param destino Ponteiro para o destino associado
         * @param codigo Código da hospedagem
         * @param nome Nome da hospedagem
         * @param dinheiro Valor da hospedagem
         * @param avaliacao Avaliação da hospedagem
         * @return true se a criação for bem-sucedida, false caso contrário
         */
        bool create(Destino* destino, Codigo codigo, Nome nome, Dinheiro dinheiro, Avaliacao avaliacao) override;

        /**
         * @brief Atualiza uma hospedagem existente
         * @param hospedagem Ponteiro para o objeto Hospedagem
         * @param nome Novo nome da hospedagem
         * @param dinheiro Novo valor da hospedagem
         * @param avaliacao Nova avaliação da hospedagem
         */
        void update(Hospedagem* hospedagem, Nome nome, Dinheiro dinheiro, Avaliacao avaliacao) override;

        /**
         * @brief Remove uma hospedagem
         * @param destino Ponteiro para o destino associado
         * @param hospedagem Ponteiro para o objeto Hospedagem a ser removido
         */
        void destroy(Destino* destino, Hospedagem* hospedagem) override;
};

/**
 * @class CntrSerCUDAtividade
 * @brief Controlador de serviço para gerenciamento de atividades
 * @details Implementa operações CRUD para entidades do tipo Atividade
 */
class CntrSerCUDAtividade : public IntSerCUDAtividade {
    public:
        /**
         * @brief Cria uma nova atividade
         * @param destino Ponteiro para o destino associado
         * @param codigo Código da atividade
         * @param nome Nome da atividade
         * @param data Data da atividade
         * @param horario Horário da atividade
         * @param duracao Duração da atividade
         * @param dinheiro Valor da atividade
         * @param avaliacao Avaliação da atividade
         * @return true se a criação for bem-sucedida, false caso contrário
         */
        bool create(Destino* destino, Codigo codigo, Nome nome, Data data, Horario horario, Duracao duracao, Dinheiro dinheiro, Avaliacao avaliacao) override;

        /**
         * @brief Atualiza uma atividade existente
         * @param atividade Ponteiro para o objeto Atividade
         * @param nome Novo nome da atividade
         * @param data Nova data da atividade
         * @param horario Novo horário da atividade
         * @param duracao Nova duração da atividade
         * @param dinheiro Novo valor da atividade
         * @param avaliacao Nova avaliação da atividade
         */
        void update(Atividade* atividade, Nome nome, Data data, Horario horario, Duracao duracao, Dinheiro dinheiro, Avaliacao avaliacao) override;

        /**
         * @brief Remove uma atividade
         * @param destino Ponteiro para o destino associado
         * @param atividade Ponteiro para o objeto Atividade a ser removido
         */
        void destroy(Destino* destino, Atividade* atividade) override;
};

#endif
