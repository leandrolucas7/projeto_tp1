#ifndef BANCO_HOSPEDAGENS_HPP
#define BANCO_HOSPEDAGENS_HPP

#include "banco_de_dados.hpp"
#include "../entidades/ENTIDADES.hpp"
#include <iostream>
using namespace std;
class BancoHospedagens : public BancoDados<Hospedagem, Hospedagem>
{
    protected:
        bool criar(Hospedagem valor) override;
        bool atualizar(Hospedagem novo_valor) override;
    public:
        BancoHospedagens();
        void test();
};

#endif