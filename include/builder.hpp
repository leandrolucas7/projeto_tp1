//232013004 e 232006832

/**
 * @file Builder.hpp
 * @brief Arquivo de cabeçalho da classe BuilderSistema.
 *
 * Este arquivo contém a definição da classe BuilderSistema, que é responsável por construir e gerenciar os controladores do sistema.
 */

#ifndef BUILDER_HPP
#define BUILDER_HPP

#include "./interfacesApr.hpp"
#include "./controladoresApr.hpp"
#include "./interfacesSer.hpp"
#include "./controladoresSer.hpp"
#include "./container.hpp"
#include "dominios/DOMINIOS.hpp"
#include "entidades/ENTIDADES.hpp"

/**
 * @brief Classe responsável por construir e gerenciar os controladores do sistema.
 *
 * A classe BuilderSistema é responsável por instanciar e fornecer acesso aos controladores de autenticação, CRUD de contas, viagens, destinos, hospedagens e atividades.
 */
class BuilderSistema
{
private:
    /**
     * @brief Implementação das interfaces e servições CRUD.
     *
     * Responsável por liberar a memória alocada para os controladores.
     */
    CntrAprInicial* cntrAprInicial; ///< Controlador de interface inicial.
    IntAprAutenticacao* cntrAprAutenticacao; ///< Interface de autenticação.

    IntAprCRUDConta* cntrAprCRUDConta; ///< Interface de CRUD para contas.
    IntSerCUDConta* cntrSerCUDConta; ///< Serviço de CUD (Create, Update, Delete) para contas.

    IntAprCRUDViagem* cntrAprCRUDViagem; ///< Interface de CRUD para viagens.
    IntSerCUDViagem* cntrSerCUDViagem; ///< Serviço de CUD para viagens.

    IntAprCRUDDestino* cntrAprCRUDDestino; ///< Interface de CRUD para destinos.
    IntSerCUDDestino* cntrSerCUDDestino; ///< Serviço de CUD para destinos.

    IntAprCRUDHospedagem* cntrAprCRUDHospedagem; ///< Interface de CRUD para hospedagens.
    IntSerCUDHospedagem* cntrSerCUDHospedagem; ///< Serviço de CUD para hospedagens.

    IntAprCRUDAtividade* cntrAprCRUDAtividade; ///< Interface de CRUD para atividades.
    IntSerCUDAtividade* cntrSerCUDAtividade; ///< Serviço de CUD para atividades.

public:
    /**
     * @brief Constrói e retorna o controlador de interface inicial.
     *
     * Este método é responsável por instanciar e retornar o controlador de interface inicial.
     *
     * @return Ponteiro para o controlador de interface inicial.
     */
    CntrAprInicial* build_cntrAprInicial();

    /**
     * @brief Destrutor da classe BuilderSistema.
     *
     * Responsável por liberar a memória alocada para os controladores.
     */
    ~BuilderSistema();
};

#endif