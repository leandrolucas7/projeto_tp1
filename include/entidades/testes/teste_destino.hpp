#ifndef TESTE_DESTINO_HPP
#define TESTE_DESTINO_HPP


#include "../ENTIDADES.hpp"
#include <vector>
#include <string>
using namespace std;


class TesteDestino
{
    private:
        const static vector<string> VALORES_VALIDOS_CODIGO;
        const static vector<string> VALORES_VALIDOS_NOME;
        const static vector<string> VALORES_VALIDOS_DATA_INICIO;
        const static vector<string> VALORES_VALIDOS_DATA_TERMINO;
        const static vector<int> VALORES_VALIDOS_AVALIACAO;
        Destino* destino;
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