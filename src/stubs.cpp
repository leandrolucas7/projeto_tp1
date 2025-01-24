#include "../include/stubs.hpp"

bool StubCntrSerAutenticacao :: autenticar(Conta conta)
{
    if (conta.get_codigo().get_valor() == "123456" && conta.get_senha().get_valor() == "69130")
    {
        return true;
    }
    return false;
}