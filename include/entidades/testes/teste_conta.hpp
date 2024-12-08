#ifndef TESTE_CONTA_HPP
#define TESTE_CONTA_HPP


#include "../ENTIDADES.hpp"
#include <vector>
#include <string>
using namespace std;


class TesteConta 
{
    private:
        const static vector<string> VALORES_VALIDOS_CODIGO;
        const static vector<string> VALORES_VALIDOS_SENHA;
        Conta *conta;
        int estado;
        void set_up();
        void tear_down();
        void testar_cenario();
    public:
        const static int SUCESSO = 1;
        const static int FALHA = 0;
        int run();
};

#endif