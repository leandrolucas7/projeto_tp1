#ifndef SUPER_TESTE_HPP
#define SUPER_TESTE_HPP

#include <vector>
#include "../dominios/super_dominio.hpp"

// Tipo do Valor do Domínio
template <typename T>
class SuperTeste 
{
    protected:
        SuperDominio<T> *dominio;
        std::vector<T> valores_validos;
        std::vector<T> valores_invalidos;
        int estado;
        virtual void set_valores() = 0;
        void set_teste();
        void tear_down();
        void testar_valores_validos();
        void testar_valores_invalidos();
    public:
        const static int SUCESSO = 1;
        const static int FALHA = 0;
        int run();
};

#endif
