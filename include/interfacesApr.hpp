//232006215

/**
 * @file interfacesApr.hpp
 * @brief Declaração das interfaces da camada de apresentação.
 *
 * Este arquivo contém a definição de diversas interfaces utilizadas na camada de apresentação do sistema.
 * Elas fornecem métodos para interação com a lógica de negócios, incluindo autenticação e operações CRUD
 * para diferentes entidades.
 */

#ifndef INTERFACES_APR_HPP
#define INTERFACES_APR_HPP

#include "dominios/DOMINIOS.hpp"
#include "entidades/ENTIDADES.hpp"
#include "./interfacesSer.hpp"

/**
 * @brief Declaração antecipada das classes da camada de apresentação.
 */
class IntAprInput;
class IntAprAutenticacao;
class IntAprCRUDConta;
template <typename T, typename U>
class IntAprCRUD;
class IntAprCRUDViagem;
class IntAprCRUDDestino;
class IntAprCRUDHospedagem;
class IntAprCRUDAtividade;
class IntSerAutenticacao;

/**
 * @brief Interface responsável pela entrada de dados do usuário.
 *
 * Fornece métodos para capturar entradas e convertê-las para os tipos apropriados.
 */
class IntAprInput
{
    public:
        virtual ~IntAprInput() {}
        virtual void limpa_buffer() = 0;
        virtual int get_user_input() = 0;
        virtual Codigo get_codigo() = 0;
        virtual Senha get_senha() = 0;
        virtual Nome get_nome() = 0;
        virtual Avaliacao get_avaliacao() = 0;
        virtual Dinheiro get_diaria() = 0;
        virtual Dinheiro get_preco() = 0;
        virtual Duracao get_duracao() = 0;
        virtual Horario get_horario() = 0;
        virtual Data get_data_inicio() = 0;
        virtual Data get_data_termino(Data) = 0;
        virtual Data get_data_atividade(Data, Data) = 0;
};

/**
 * @brief Módulo para autenticação de usuários.
 *
 * Define operações para validação e associação com o gerenciamento de contas.
 */
class IntAprAutenticacao
{
    public:
        virtual ~IntAprAutenticacao() {} 
        virtual void set_cntrAprCRUDConta(IntAprCRUDConta*) = 0;
        virtual void autenticar(Conta*&) = 0;
};

/**
 * @brief Componente de manipulação de contas.
 *
 * Fornece operações para criação, leitura, atualização e exclusão de contas.
 */
class IntAprCRUDConta
{
    public:
        virtual ~IntAprCRUDConta() {}
        virtual void set_cntrSerCUDConta(IntSerCUDConta*) = 0;
        virtual void set_cntrAprCRUDViagem(IntAprCRUDViagem*) = 0;
        virtual void create(Conta*&) = 0;
        virtual void read(Conta*&) = 0;
        virtual void update(Conta*&) = 0;
        virtual bool destroy(Conta*&) = 0;
};

/**
 * @brief Modelo genérico para operações CRUD.
 *
 * @tparam T Tipo principal manipulado.
 * @tparam U Tipo auxiliar envolvido na operação.
 */
template <typename T, typename U>
class IntAprCRUD
{
    public:
        virtual ~IntAprCRUD() {}
        virtual void create(T*&) = 0;
        virtual void read(T*&, U*&) = 0;
        virtual void update(T*&, U*&) = 0;
        virtual bool destroy(T*&, U*&) = 0;
};

/**
 * @brief Gerenciamento de viagens.
 *
 * Define operações para manipular viagens associadas a um usuário.
 */
class IntAprCRUDViagem : public IntAprCRUD<Conta, Viagem>
{
    public:
        virtual void set_cntrSerCUDViagem(IntSerCUDViagem*) = 0;
        virtual void set_cntrAprCRUDDestino(IntAprCRUDDestino*) = 0;
        virtual void create(Conta*&) = 0;
        virtual void read(Conta*&, Viagem*&) = 0;
        virtual void update(Conta*&, Viagem*&) = 0;
        virtual bool destroy(Conta*&, Viagem*&) = 0;
};

/**
 * @brief Controle sobre destinos de viagem.
 *
 * Oferece funcionalidades para manipulação de destinos dentro de uma viagem.
 */
class IntAprCRUDDestino : public IntAprCRUD<Viagem, Destino>
{
    public:
        virtual void set_cntrSerCUDDestino(IntSerCUDDestino*) = 0;
        virtual void set_cntrAprCRUDHospedagem(IntAprCRUDHospedagem*) = 0;
        virtual void set_cntrAprCRUDAtividade(IntAprCRUDAtividade*) = 0;
        virtual void create(Viagem*&) = 0;
        virtual void read(Viagem*&, Destino*&) = 0;
        virtual void update(Viagem*&, Destino*&) = 0;
        virtual bool destroy(Viagem*&, Destino*&) = 0;
};

/**
 * @brief Administração de hospedagens.
 *
 * Gerencia hospedagens dentro de um destino.
 */
class IntAprCRUDHospedagem : public IntAprCRUD<Destino, Hospedagem>
{
    public:
        virtual void set_cntrSerCUDHospedagem(IntSerCUDHospedagem*) = 0;
        virtual void create(Destino*&) = 0;
        virtual void read(Destino*&, Hospedagem*&) = 0;
        virtual void update(Destino*&, Hospedagem*&) = 0;
        virtual bool destroy(Destino*&, Hospedagem*&) = 0;
};

/**
 * @brief Coordenação de atividades.
 *
 * Realiza operações relacionadas a atividades planejadas em um destino.
 */
class IntAprCRUDAtividade : public IntAprCRUD<Destino, Atividade>
{
    public:
        virtual void set_cntrSerCUDAtividade(IntSerCUDAtividade*) = 0;
        virtual void create(Destino*&) = 0;
        virtual void read(Destino*&, Atividade*&) = 0;
        virtual void update(Destino*&, Atividade*&) = 0;
        virtual bool destroy(Destino*&, Atividade*&) = 0;
};

#endif // INTERFACES_APR_HPP