#ifndef TESTE_HOSPEDAGEM_HPP
#define TESTE_HOSPEDAGEM_HPP

#include "../ENTIDADES.hpp"
#include <vector>
#include <string>
using namespace std;


class TesteHospedagem
{
    private:
        const static vector<string> VALORES_VALIDOS_CODIGO;
        const static vector<string> VALORES_VALIDOS_NOME;
        const static vector<double> VALORES_VALIDOS_DIARIA;
        const static vector<int> VALORES_VALIDOS_AVALIACAO;
        Hospedagem* hospedagem;
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