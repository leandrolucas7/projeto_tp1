#ifndef BANCO_DADOS_HPP
#define BANCO_DADOS_HPP

#include <iostream>
#include <unordered_map>

using namespace std;

// T: Struct que é armazenada
// U: Tipo da informação 
template <typename T, typename U>
class BancoDados 
{
    protected:
        unordered_map<string, T> dados;                
        virtual bool criar(U valor) = 0;
        virtual bool atualizar(U valor) = 0;
        void verificar(string codigo);
        T ler(string codigo);
        bool excluir(string codigo);
};

#endif
