// Matrícula: 232006215
/**
 * @file data.hpp
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
 *  - "DD" representa um dia. O dia não pode ser um número negativo e o número de dias varia de acordo com o mês. Assim, para que a data seja validada, consideramos que:
 *      - O mês de fevereiro tem 29 dias em anos bissextos e 28 dias nos outros anos;
 *      - Os meses com 30 dias são abril,junho,setembro e novembro;
 *      - Os meses com 31 dias são janeiro, março, maio, julho, agosto, outubro e dezembro.
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
