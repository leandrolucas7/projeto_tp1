// Matrícula: 222025852
/**
 * @file Avaliacao.hpp
 * @brief Declaração da classe `Avaliacao`.
 * 
 */

#ifndef AVALIACAO_HPP
#define AVALIACAO_HPP

#include "super_dominio.hpp"

/**
 * @class Avaliacao
 * @brief Classe representa a pontuação de determinado serviço.
 * 
 * Armazena o valor da pontuação como um número inteiro.
 * 
 * Regras de validação implementadas no método privado `validar`.
 * 
 * <b>Regras de formato:</b>
 * 
 * - Armazena apenas valores inteiros de 0 a 5, extremos inclusos.
 * 
 */

class Avaliacao : public SuperDominio<int>
{
private:
    void validar(int valor) override;
};

#endif // AVALIACAO_HPP
