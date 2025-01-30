//232023969

#ifndef controladoresApr_HPP
#define controladoresApr_HPP

#include "./interfacesApr.hpp"
#include "./interfacesSer.hpp"
#include "dominios/DOMINIOS.hpp"
#include "entidades/ENTIDADES.hpp"
#include <iostream>

// Declaração das classes controladoras
class CntrAprInicial;
class CntrAprInput;
class CntrAprAutenticacao;
class CntrAprCRUDConta;
class CntrAprCRUDViagem;
class CntrAprCRUDDestino;
class CntrAprCRUDHospedagem;
class CntrAprCRUDAtividade;

/**
 * @brief Classe responsável pela inicialização do sistema e controle de fluxo.
 */
class CntrAprInicial
{
    private:
        bool usuarioLogado; ///< Indica se o usuário está autenticado.
        IntAprCRUDConta* cntrAprCRUDConta; ///< Controlador CRUD de conta.
        IntAprAutenticacao* cntrAprAutenticacao; ///< Controlador de autenticação.
    public:
        CntrAprInicial() {}
        void set_cntrAprCRUDConta(IntAprCRUDConta*);
        void set_cntrAprAutenticacao(IntAprAutenticacao*);
        void executar();
};

/**
 * @brief Classe Singleton para manipulação de entrada do usuário.
 */
class CntrAprInput : public IntAprInput
{
    private:
        static CntrAprInput* instancia; ///< Instância única da classe.
        CntrAprInput(){}
        ~CntrAprInput(){}
        CntrAprInput(const CntrAprInput&) = delete;
        CntrAprInput& operator=(const CntrAprInput&) = delete;
    public:
        static CntrAprInput* get_instancia(); ///< Retorna a instância única.
        static void delete_instancia(); ///< Deleta a instância existente.
        void limpa_buffer() override;
        int get_user_input() override;
        Codigo get_codigo() override;
        Senha get_senha() override;
        Nome get_nome() override;
        Dinheiro get_diaria() override;
        Dinheiro get_preco() override;
        Duracao get_duracao() override;
        Horario get_horario() override;
        Avaliacao get_avaliacao() override;
        Data get_data_inicio() override;
        Data get_data_termino(Data) override;
        Data get_data_atividade(Data, Data) override;
};

/**
 * @brief Classe de controle de autenticação de usuários.
 */
class CntrAprAutenticacao : public IntAprAutenticacao
{
    private:
        IntAprCRUDConta* cntrAprCRUDConta; ///< Controlador CRUD de conta.
    public:
        void set_cntrAprCRUDConta(IntAprCRUDConta*) override;
        void autenticar(Conta*) override;
};

// Classes de controle para operações CRUD em diferentes entidades

class CntrAprCRUDConta : public IntAprCRUDConta
{
    private:
        IntSerCUDConta* cntrSerCUDConta;
        IntAprCRUDViagem* cntrAprCRUDViagem;
    public:
        void set_cntrSerCUDConta(IntSerCUDConta*) override;
        void set_cntrAprCRUDViagem(IntAprCRUDViagem*) override;
        void create(Conta*) override;
        void read(Conta*) override;
        void update(Conta*) override;
        bool destroy(Conta*) override;
};

// Implementações semelhantes para Viagem, Destino, Hospedagem e Atividade

// Definições inline dos setters
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

// Outras implementações de setters

#endif
