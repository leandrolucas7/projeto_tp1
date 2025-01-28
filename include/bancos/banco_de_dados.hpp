#ifndef BANCO_DADOS_HPP
#define BANCO_DADOS_HPP

#include <iostream>
#include <unordered_map>

using namespace std;

// T: Struct ou entidade que é armazenada
// U: Tipo da informação que será atualizada
template <typename T, typename U>
class BancoDados 
{
    protected:
        unordered_map<string, T> dados;                
        virtual bool criar(string codigo, string senha) = 0;
        virtual bool atualizar(string codigo, U novo_valor) = 0;
        void verificar(string codigo);
        T ler(string codigo);
        bool excluir(string codigo);
};

#endif
