#include "../../../include/modulos/apresentacao/mod_apr_autenticacao.hpp"
#include "../../stubs/stub_mod_ser_autenticacao.cpp"
#include "../../../include/entidades/conta.hpp"

bool ModAprAutenticacao::autenticar(Codigo* codigo, Senha* senha)
{
    Conta conta;
    conta.set_codigo(*codigo);
    conta.set_senha(*senha);
    
    StubModSerAutenticacao* mod_ser_autenticacao = new StubModSerAutenticacao();
    return mod_ser_autenticacao->autenticar(conta);
}
