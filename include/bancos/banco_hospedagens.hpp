#ifndef BANCO_HOSPEDAGENS_HPP
#define BANCO_HOSPEDAGENS_HPP

#include "banco_de_dados.hpp"
#include "../entidades/ENTIDADES.hpp"

class BancoHospedagens : public BancoDados<Hospedagem, string>
{
    protected:
        bool criar(string codigo, string senha) override;
        bool atualizar(string codigo, string novo_valor) override;
    public:
        void test(string s1, string s2)
        {
            criar(s1, s2);
            atualizar(s1, s2);
        }
};

#endif