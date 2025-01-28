#include <iostream>
#include "../../include/entidades/ENTIDADES.hpp"
#include "../../include/interfaces/INTERFACES.hpp"
#include "../../include/modulos/MODULOS.hpp"

int main()
{
    // Criando instâncias de Codigo e Senha
    //Codigo codigo_teste;
    //Senha senha_teste;
    Conta conta_teste;

    //codigo_teste.set_valor("123456");
    //senha_teste.set_valor("69130");


    // Criando uma instância de ModAprAutenticacao e testando autenticação
    ModAprAutenticacao mod_apr_autenticacao;
    if (mod_apr_autenticacao.autenticar(&conta_teste))
    {
        std::cout << "Autenticacao bem-sucedida!" << std::endl;
    }
    else
    {
        std::cout << "Falha na autenticacao!" << std::endl;
    }

    return 0;
}
