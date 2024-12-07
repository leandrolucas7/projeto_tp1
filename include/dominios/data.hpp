// Matrícula: 232006215
/**
 * @file Data.hpp
 * @brief Declaração da classe `Data`.
 * 
 */

#ifndef DATA_HPP
#define DATA_HPP

#include "super_dominio.hpp"
#include <string>
using namespace std;

/**
 * @class Data
 * @brief Classe que referencia um dia no calendário.
 * 
 * Guarda um ponto no tempo como string no formato de dia, mês e ano.
 * 
 * 
 * <b>Regras de formato:</b>
 * 
 * - A string que representa a data deve estar no formato "DD-MM-AA", onde:
 *  - "AA" representa um ano de "00" a "99";
 *  - "MM" representa um mês, de janeiro("01") a dezembro("12");
 *  - "DD" representa um dia. O dia não pode ser um número negativoe o número de dias varia de acordo com o mês. Assim, para que a data seja validada, consideramos que:
*       - Janeiro possui 31 dias;
*       - Fevereiro tem 29 dias em anos bissextos e 28 dias nos outros anos;
*       - Março possui 31 dias;
*       - Abril possui 30 dias;
*       - Maio possui 31 dias;
*       - Junho possui 30 dias;
*       - Julho possui 31 dias;
*       - Agosto possui 31 dias;
*       - Setembro possui 30 dias;
*       - Outubro possui 31 dias;
*       - Novembro possui 30 dias;
*       - Dezembro possui 31 dias;
*       .
*   .
* .
* @note Anos bissextos são aqueles que são divisíveis por 4
*/

class Data : public SuperDominio<string>
{
    private:
        void validar(string) override;
};


#endif
