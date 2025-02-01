//232023969

#ifndef controladoresApr_HPP
#define controladoresApr_HPP

#include "./interfacesApr.hpp"
#include "./interfacesSer.hpp"
#include "dominios/DOMINIOS.hpp"
#include "entidades/ENTIDADES.hpp"
#include <iostream>

// Declarações antecipadas das classes controladoras
class CntrAprInicial;
class CntrAprInput;
class CntrAprAutenticacao;
class CntrAprCRUDConta;
class CntrAprCRUDViagem;
class CntrAprCRUDDestino;
class CntrAprCRUDHospedagem;
class CntrAprCRUDAtividade;

/**
 * @brief Controlador principal que serve como ponto de entrada da aplicação
 * 
 * Esta classe gerencia o fluxo inicial da aplicação, tratando da autenticação
 * do usuário e coordenando entre os controladores de conta e autenticação.
 */
class CntrAprInicial
{
    private:
        bool usuarioLogado;                        ///< Indica se há um usuário logado no sistema
        IntAprCRUDConta* cntrAprCRUDConta;        ///< Ponteiro para o controlador de gerenciamento de conta
        IntAprAutenticacao* cntrAprAutenticacao;   ///< Ponteiro para o controlador de autenticação
    public:
        /// @brief Construtor padrão
        CntrAprInicial() {}
        
        /**
         * @brief Define o controlador de gerenciamento de conta
         * @param ptr Ponteiro para o controlador de gerenciamento de conta
         */
        void set_cntrAprCRUDConta(IntAprCRUDConta*);
        
        /**
         * @brief Define o controlador de autenticação
         * @param ptr Ponteiro para o controlador de autenticação
         */
        void set_cntrAprAutenticacao(IntAprAutenticacao*);
        
        /**
         * @brief Executa o fluxo principal da aplicação
         */
        void executar();
};

/**
 * @brief Classe Singleton que gerencia todas as operações de entrada do usuário
 * 
 * Esta classe implementa o padrão Singleton e fornece métodos
 * para gerenciar diversos tipos de entrada do usuário, incluindo validação de formulários.
 */
class CntrAprInput : public IntAprInput
{
    private:
        int contador = 0;
        static CntrAprInput* instancia;            ///< Instância única da classe
        CntrAprInput(){}                          ///< Construtor privado
        ~CntrAprInput(){}                         ///< Destrutor privado
        CntrAprInput(const CntrAprInput&) = delete; ///< Construtor de cópia deletado
        CntrAprInput& operator=(const CntrAprInput&) = delete; ///< Operador de atribuição deletado
    
    public:
        /**
         * @brief Obtém a instância única da classe
         * @return Ponteiro para a instância singleton
         */
        static CntrAprInput* get_instancia();
        
        /**
         * @brief Deleta a instância singleton
         */
        static void delete_instancia();
        
        void limpa_buffer() override;              ///< Limpa o buffer de entrada
        int get_user_input() override;             ///< Obtém entrada genérica do usuário
        Codigo get_codigo() override;              ///< Obtém entrada de código
        Senha get_senha() override;                ///< Obtém entrada de senha
        Nome get_nome() override;                  ///< Obtém entrada de nome
        Dinheiro get_diaria() override;            ///< Obtém entrada de valor diário
        Dinheiro get_preco() override;             ///< Obtém entrada de preço
        Duracao get_duracao() override;            ///< Obtém entrada de duração
        Horario get_horario() override;            ///< Obtém entrada de horário
        Avaliacao get_avaliacao() override;        ///< Obtém entrada de avaliação
        Data get_data_inicio() override;           ///< Obtém data de início
        Data get_data_termino(Data) override;      ///< Obtém data de término baseada na data de início
        Data get_data_atividade(Data, Data) override; ///< Obtém data da atividade dentro das datas da viagem
};

/**
 * @brief Gerencia processos de autenticação de usuários
 */
class CntrAprAutenticacao : public IntAprAutenticacao
{
    private:
        IntAprCRUDConta* cntrAprCRUDConta;        ///< Ponteiro para interface de gerenciamento de conta
    public:
        void set_cntrAprCRUDConta(IntAprCRUDConta*) override;
        void autenticar(Conta*&) override;          ///< Realiza autenticação do usuário
};

/**
 * @brief Gerencia operações CRUD relacionadas a contas
 */
class CntrAprCRUDConta : public IntAprCRUDConta
{
    private:
        IntSerCUDConta* cntrSerCUDConta;          ///< Interface da camada de serviço para operações de conta
        IntAprCRUDViagem* cntrAprCRUDViagem;      ///< Interface de gerenciamento de viagem
    public:
        void set_cntrSerCUDConta(IntSerCUDConta*) override;
        void set_cntrAprCRUDViagem(IntAprCRUDViagem*) override;
        void create(Conta*&) override;              ///< Cria nova conta
        void read(Conta*&) override;                ///< Recupera informações da conta
        void update(Conta*&) override;              ///< Atualiza informações da conta
        bool destroy(Conta*&) override;             ///< Remove conta
};

/**
 * @brief Gerencia operações CRUD relacionadas a viagens
 */
class CntrAprCRUDViagem : public IntAprCRUDViagem
{
    private:
        IntSerCUDViagem* cntrSerCUDViagem;        ///< Interface da camada de serviço para operações de viagem
        IntAprCRUDDestino* cntrAprCRUDDestino;    ///< Interface de gerenciamento de destino
    public:
        void set_cntrSerCUDViagem(IntSerCUDViagem*) override;
        void set_cntrAprCRUDDestino(IntAprCRUDDestino*) override;
        void create(Conta*&) override;              ///< Cria nova viagem
        void read(Conta*&,Viagem*&) override;        ///< Recupera informações da viagem
        void update(Conta*&,Viagem*&) override;      ///< Atualiza informações da viagem
        bool destroy(Conta*&,Viagem*&) override;     ///< Remove viagem
};

/**
 * @brief Gerencia operações CRUD relacionadas a destinos
 */
class CntrAprCRUDDestino : public IntAprCRUDDestino
{
    private:
        IntSerCUDDestino* cntrSerCUDDestino;      ///< Interface da camada de serviço para operações de destino
        IntAprCRUDHospedagem* cntrAprCRUDHospedagem; ///< Interface de gerenciamento de hospedagem
        IntAprCRUDAtividade* cntrAprCRUDAtividade;   ///< Interface de gerenciamento de atividade
    public:
        void set_cntrSerCUDDestino(IntSerCUDDestino*) override;
        void set_cntrAprCRUDHospedagem(IntAprCRUDHospedagem*) override;
        void set_cntrAprCRUDAtividade(IntAprCRUDAtividade*) override;
        void create(Viagem*&) override;             ///< Cria novo destino
        void read(Viagem*&,Destino*&) override;      ///< Recupera informações do destino
        void update(Viagem*&,Destino*&) override;    ///< Atualiza informações do destino
        bool destroy(Viagem*&,Destino*&) override;   ///< Remove destino
};

/**
 * @brief Gerencia operações CRUD relacionadas a hospedagens
 */
class CntrAprCRUDHospedagem : public IntAprCRUDHospedagem
{
    private:
        IntSerCUDHospedagem* cntrSerCUDHospedagem; ///< Interface da camada de serviço para operações de hospedagem
    public:
        void set_cntrSerCUDHospedagem(IntSerCUDHospedagem*) override;
        void create(Destino*&) override;            ///< Cria nova hospedagem
        void read(Destino*&,Hospedagem*&) override;  ///< Recupera informações da hospedagem
        void update(Destino*&,Hospedagem*&) override; ///< Atualiza informações da hospedagem
        bool destroy(Destino*&,Hospedagem*&) override; ///< Remove hospedagem
};

/**
 * @brief Gerencia operações CRUD relacionadas a atividades
 */
class CntrAprCRUDAtividade : public IntAprCRUDAtividade
{
    private:
        IntSerCUDAtividade* cntrSerCUDAtividade;   ///< Interface da camada de serviço para operações de atividade
    public:
        void set_cntrSerCUDAtividade(IntSerCUDAtividade*);
        void create(Destino*&) override;            ///< Cria nova atividade
        void read(Destino*&,Atividade*&) override;   ///< Recupera informações da atividade
        void update(Destino*&,Atividade*&) override; ///< Atualiza informações da atividade
        bool destroy(Destino*&,Atividade*&) override; ///< Remove atividade
};

// Implementações inline dos métodos set

inline void CntrAprInicial::set_cntrAprCRUDConta(IntAprCRUDConta* ptr)
{
    cntrAprCRUDConta = ptr;
}

inline void CntrAprInicial::set_cntrAprAutenticacao(IntAprAutenticacao* ptr)
{
    cntrAprAutenticacao = ptr;
}

inline void CntrAprAutenticacao::set_cntrAprCRUDConta(IntAprCRUDConta* ptr)
{
    cntrAprCRUDConta = ptr;
}

inline void CntrAprCRUDConta::set_cntrSerCUDConta(IntSerCUDConta* ptr)
{
    cntrSerCUDConta = ptr;
}

inline void CntrAprCRUDConta::set_cntrAprCRUDViagem(IntAprCRUDViagem* ptr)
{
    cntrAprCRUDViagem = ptr;
}

inline void CntrAprCRUDViagem::set_cntrSerCUDViagem(IntSerCUDViagem* ptr)
{
    cntrSerCUDViagem = ptr;
}

inline void CntrAprCRUDViagem::set_cntrAprCRUDDestino(IntAprCRUDDestino* ptr)
{
    cntrAprCRUDDestino = ptr;
}

inline void CntrAprCRUDDestino::set_cntrSerCUDDestino(IntSerCUDDestino* ptr)
{
    cntrSerCUDDestino = ptr;
}

inline void CntrAprCRUDDestino::set_cntrAprCRUDHospedagem(IntAprCRUDHospedagem* ptr)
{
    cntrAprCRUDHospedagem = ptr;
}

inline void CntrAprCRUDDestino::set_cntrAprCRUDAtividade(IntAprCRUDAtividade* ptr)
{
    cntrAprCRUDAtividade = ptr;
}

inline void CntrAprCRUDHospedagem::set_cntrSerCUDHospedagem(IntSerCUDHospedagem* ptr)
{
    cntrSerCUDHospedagem = ptr;
}

inline void CntrAprCRUDAtividade::set_cntrSerCUDAtividade(IntSerCUDAtividade* ptr)
{
    cntrSerCUDAtividade = ptr;
}

#endif // CONTROLADORES_APR_HPP
