// Matrícula: 222025852
/**
 * @file Horario.hpp
 * @brief Declaração da classe `Horario`.
 * 
 */

#ifndef HORARIO_HPP
#define HORARIO_HPP

#include "super_dominio.hpp"
#include <string>
using namespace std;

/**
 * @class Horario
 * @brief Classe que representa um valor de tempo em formato textual.
 * 
 * Armazena a representação textual de um instante de tempo como string.
 * 
 * Regras de validação implementadas no método privado `validar`.
 * 
 * <b>Regras de formato:</b>
 * 
 * - O Conteúdo da string deve ser "HH:MM", com:
 *  - HH entre "00" e "23", extremos inclusos; 
 *  - MM entre "00" e "59", extremos inclusos.
 */
class Horario : public SuperDominio<string>
{
private:
    void validar(string valor) override;
};

#endif // HORARIO_HPP
