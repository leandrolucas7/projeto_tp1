// Matrícula: 222025852
/**
 * @file Horario.hpp
 * @brief Declaração da classe `Horario`, que representa um horário no formato de string.
 * 
 * A classe `Horario` herda de `SuperDominio` e implementa a validação específica 
 * para valores do tipo `std::string` que representam horários.
 */

#ifndef HORARIO_HPP
#define HORARIO_HPP

#include "super_dominio.hpp"
#include <string>
using namespace std;

/**
 * @class Horario
 * @brief Classe que representa um horário como uma string.
 * 
 * A classe `Horario` deriva de `SuperDominio<std::string>` e implementa o método de validação
 * para garantir que o valor fornecido seja um horário válido em formato adequado.
 * 
 * O formato esperado pode seguir, por exemplo, o padrão `HH:MM` (24 horas). 
 * A lógica de validação deve ser implementada no método `validar`.
 */
class Horario : public SuperDominio<string>
{
private:
    /**
     * @brief Valida o valor do horário.
     * 
     * Implementa as regras específicas de validação para horários, garantindo que 
     * o valor fornecido esteja em um formato adequado (ex.: `HH:MM`) e dentro do intervalo válido.
     * 
     * @param[in] valor Valor string representando o horário a ser validado.
     * @throws std::invalid_argument Caso o valor não esteja no formato ou intervalo esperado.
     */
    void validar(string valor) override;
};

#endif // HORARIO_HPP
