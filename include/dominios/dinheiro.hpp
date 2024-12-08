//Matrícula: 232006215

/**
 * @file horario.hpp
 * @brief Declaração da classe `Data`.
 * 
 */


#ifndef DINHEIRO_HPP
#define DINHEIRO_HPP

#include "super_dominio.hpp"
#include <string>
using namespace std;

/**
 * @class Dinheiro
 * @brief Classe que armazena um double que representa valor pecuniário.
 * 
 * <b>Regras de formato:</b>
 * - O valor monetário não pode ser negativo nem exceder 200000;
 * - O ponto (".") deve ser usado como separador decimal;
 * - Após o ponto, são aceitos dígitos significativos apenas nas duas primeiras casas decimais. Desse modo, os valores "20", "300.15" e "240.750", por exemplo, seriam validados, ao passo que "1.009", "12.123" e "457.122" seriam rejeitados.
 * 
 */


class Dinheiro : public SuperDominio<double>
{
    private:
        void validar(double) override;
};


#endif
