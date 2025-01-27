#include "../include/builder.hpp"

//ContainerContas* ContainerContas::instancia = nullptr;

CntrAprInicial* BuilderSistema::build_cntrAprInicial()
{

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
    
    return this->cntrAprInicial;
}

BuilderSistema::~BuilderSistema()
{
    ContainerContas::delete_instancia();
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