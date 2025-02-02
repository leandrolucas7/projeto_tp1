//232013004

/**
 * @file builder.hpp
 * @brief Definição da classe responsável por construir os componentes do sistema.
 *
 * Este arquivo contém a implementação da classe BuilderSistema, que gerencia a inicialização
 * e interligação dos controladores e interfaces do sistema.
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
 * @brief Classe responsável pela construção e configuração dos componentes do sistema.
 *
 * Esta classe gerencia a criação e interligação dos diferentes controladores e interfaces
 * que compõem o sistema.
 */
class BuilderSistema
{
    private:
        CntrAprInicial* cntrAprInicial; /**< Controlador da interface inicial. */
        IntAprAutenticacao* cntrAprAutenticacao; /**< Interface de autenticação da camada de apresentação. */

        IntAprCRUDConta* cntrAprCRUDConta; /**< Interface de gerenciamento de contas na camada de apresentação. */
        IntSerCUDConta* cntrSerCUDConta; /**< Interface de gerenciamento de contas na camada de serviços. */

        IntAprCRUDViagem* cntrAprCRUDViagem; /**< Interface de gerenciamento de viagens na camada de apresentação. */
        IntSerCUDViagem* cntrSerCUDViagem; /**< Interface de gerenciamento de viagens na camada de serviços. */

        IntAprCRUDDestino* cntrAprCRUDDestino; /**< Interface de gerenciamento de destinos na camada de apresentação. */
        IntSerCUDDestino* cntrSerCUDDestino; /**< Interface de gerenciamento de destinos na camada de serviços. */

        IntAprCRUDHospedagem* cntrAprCRUDHospedagem; /**< Interface de gerenciamento de hospedagens na camada de apresentação. */
        IntSerCUDHospedagem* cntrSerCUDHospedagem; /**< Interface de gerenciamento de hospedagens na camada de serviços. */

        IntAprCRUDAtividade* cntrAprCRUDAtividade; /**< Interface de gerenciamento de atividades na camada de apresentação. */
        IntSerCUDAtividade* cntrSerCUDAtividade; /**< Interface de gerenciamento de atividades na camada de serviços. */
        
    public:
        /**
         * @brief Constrói e retorna o controlador da interface inicial.
         *
         * @return Ponteiro para o controlador inicial do sistema.
         */
        CntrAprInicial* build_cntrAprInicial();

        /**
         * @brief Destrutor da classe.
         */
        ~BuilderSistema();
};

#endif // BUILDER_HPP
