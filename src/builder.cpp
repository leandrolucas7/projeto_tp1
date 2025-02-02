////232013004 e 232006832

#include "../include/builder.hpp"
#include "../include/controladoresApr.hpp"

/**
 * @file builder.cpp
 * @brief Implementação da classe BuilderSistema.
 *
 * Este arquivo contém a implementação dos métodos da classe BuilderSistema, responsável por construir e configurar os controladores do sistema.
 */

//ContainerContas* ContainerContas::instancia = nullptr;

/**
 * @brief Constrói e configura os controladores do sistema.
 *
 * Este método instancia todos os controladores necessários para o funcionamento do sistema e configura as dependências entre eles.
 * Ele retorna o controlador inicial, que é o ponto de entrada do sistema.
 *
 * @return Ponteiro para o controlador inicial (CntrAprInicial).
 */
CntrAprInicial* BuilderSistema::build_cntrAprInicial()
{
    // Instanciação dos controladores
    this->cntrAprInicial = new CntrAprInicial();
    this->cntrAprAutenticacao = new CntrAprAutenticacao();

    this->cntrAprCRUDConta = new CntrAprCRUDConta();
    this->cntrSerCUDConta = new CntrSerCUDConta();

    this->cntrAprCRUDViagem = new CntrAprCRUDViagem();
    this->cntrSerCUDViagem = new CntrSerCUDViagem();

    this->cntrAprCRUDDestino = new CntrAprCRUDDestino();
    this->cntrSerCUDDestino = new CntrSerCUDDestino();

    this->cntrAprCRUDHospedagem = new CntrAprCRUDHospedagem();
    this->cntrSerCUDHospedagem = new CntrSerCUDHospedagem();

    this->cntrAprCRUDAtividade = new CntrAprCRUDAtividade();
    this->cntrSerCUDAtividade = new CntrSerCUDAtividade();

    // Configuração das dependências entre os controladores
    this->cntrAprInicial->set_cntrAprAutenticacao(this->cntrAprAutenticacao);
    this->cntrAprInicial->set_cntrAprCRUDConta(this->cntrAprCRUDConta);

    this->cntrAprAutenticacao->set_cntrAprCRUDConta(this->cntrAprCRUDConta);

    this->cntrAprCRUDConta->set_cntrSerCUDConta(this->cntrSerCUDConta);
    this->cntrAprCRUDConta->set_cntrAprCRUDViagem(this->cntrAprCRUDViagem);

    this->cntrAprCRUDViagem->set_cntrSerCUDViagem(this->cntrSerCUDViagem);
    this->cntrAprCRUDViagem->set_cntrAprCRUDDestino(this->cntrAprCRUDDestino);

    this->cntrAprCRUDDestino->set_cntrSerCUDDestino(this->cntrSerCUDDestino);
    this->cntrAprCRUDDestino->set_cntrAprCRUDHospedagem(this->cntrAprCRUDHospedagem);
    this->cntrAprCRUDDestino->set_cntrAprCRUDAtividade(this->cntrAprCRUDAtividade);

    this->cntrAprCRUDHospedagem->set_cntrSerCUDHospedagem(this->cntrSerCUDHospedagem);

    this->cntrAprCRUDAtividade->set_cntrSerCUDAtividade(this->cntrSerCUDAtividade);

    // Retorna o controlador inicial configurado
    return this->cntrAprInicial;
}

/**
 * @brief Destrutor da classe BuilderSistema.
 *
 * Este método libera a memória alocada para todos os controladores instanciados durante a execução do programa.
 * Além disso, deleta a instância do contêiner de contas, se existir.
 */
BuilderSistema::~BuilderSistema()
{
    // Libera a instância do contêiner de contas
    ContainerContas::delete_instancia();

    // Libera a memória dos controladores
    delete this->cntrAprInicial;
    delete this->cntrAprAutenticacao;
    delete this->cntrAprCRUDConta;
    delete this->cntrSerCUDConta;
    delete this->cntrAprCRUDViagem;
    delete this->cntrSerCUDViagem;
    delete this->cntrAprCRUDDestino;
    delete this->cntrSerCUDDestino;
    delete this->cntrAprCRUDHospedagem;
    delete this->cntrAprCRUDAtividade;
    delete this->cntrSerCUDHospedagem;
    delete this->cntrSerCUDAtividade;
}