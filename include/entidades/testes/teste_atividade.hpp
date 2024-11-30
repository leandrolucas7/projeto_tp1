#ifndef TESTE_ATIVIDADE_HPP
#define TESTE_ATIVIDADE_HPP

#include "../ENTIDADES.hpp"
#include <vector>
#include <string>
using namespace std;

class TesteAtividade
{
    private:
        const static vector<string> VALORES_VALIDOS_CODIGO;
        const static vector<string> VALORES_VALIDOS_NOME;
        const static vector<string> VALORES_VALIDOS_DATA;
        const static vector<string> VALORES_VALIDOS_HORARIO;
        const static vector<int> VALORES_VALIDOS_DURACAO;
        const static vector<double> VALORES_VALIDOS_PRECO;
        const static vector<int> VALORES_VALIDOS_AVALIACAO;
        Atividade* atividade;
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