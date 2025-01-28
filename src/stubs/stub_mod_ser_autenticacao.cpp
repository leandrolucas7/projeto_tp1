#include "../../include/entidades/conta.hpp"

class StubModSerAutenticacao
{
    public:
        bool autenticar(Conta conta)
        {
            if (conta.get_codigo().get_valor() == "123456" && conta.get_senha().get_valor() == "69130")
            {
                return true;
            }
            return false;
        }      
};