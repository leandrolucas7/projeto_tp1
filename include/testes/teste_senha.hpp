#ifndef TESTE_SENHA_HPP
#define TESTE_SENHA_HPP

#include "super_teste.hpp"
#include <string>
using namespace std;

class TesteSenha : public SuperTeste<string> 
{
  protected:
    void set_valores() override;    
};

#endif