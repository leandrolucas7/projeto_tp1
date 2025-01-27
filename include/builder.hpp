#ifndef BUILDER_HPP
#define BUILDER_HPP

#include "./interfacesApr.hpp"
#include "./controladoresApr.hpp"
#include "./interfacesSer.hpp"
#include "./controladoresSer.hpp"
#include "./container.hpp"
#include "./stubs.hpp"
#include "dominios/DOMINIOS.hpp"
#include "entidades/ENTIDADES.hpp"


class BuilderSistema
{
    private:
        CntrAprInicial* cntrAprInicial;
        IntAprAutenticacao* cntrAprAutenticacao;

        IntAprCRUDConta* cntrAprCRUDConta;
        IntSerCUDConta* cntrSerCUDConta;

        IntAprCRUDViagem* cntrAprCRUDViagem;
        IntSerCUDViagem* cntrSerCUDViagem;

        IntAprCRUDDestino* cntrAprCRUDDestino;
        IntSerCUDDestino* cntrSerCUDDestino;

        IntAprCRUDHospedagem* cntrAprCRUDHospedagem;
        IntSerCUDHospedagem* cntrSerCUDHospedagem;

        IntAprCRUDAtividade* cntrAprCRUDAtividade;
        IntSerCUDAtividade* cntrSerCUDAtividade;
        
    public:
        CntrAprInicial* build_cntrAprInicial();
        ~BuilderSistema();

};

#endif