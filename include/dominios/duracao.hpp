// Matrícula: 232006832
/**
 * @file duracao.hpp
 * @brief Declaração da classe 'Duracao'.
 */


#ifndef DURACAO_HPP
#define DURACAO_HPP

/**
 * @class Horario
 * @brief Classe responsável por armazenar um período de tempo com critérios de validação.
 * 
 * Armazena o valor do período de tempo como um inteiro.
 * 
 * Regras de validação implementadas no método privado `validar`.
 * 
 * <b>Regras de formato:</b>
 * 
 * - Armazena apenas valores inteiros entre 0 e 360, com os extremos inclusos.
 */

#include "super_dominio.hpp"

class Duracao : public SuperDominio<int>
{
    private:
        void validar(int) override;
};

#endif
