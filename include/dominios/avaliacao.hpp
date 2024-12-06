// Matrícula: 222025852
/**
 * @file Avaliacao.hpp
 * @brief Declaração da classe `Avaliacao`, que representa uma avaliação com valor numérico.
 * 
 * A classe `Avaliacao` herda de `SuperDominio` e implementa a lógica de validação específica 
 * para valores inteiros representando avaliações.
 */

#ifndef AVALIACAO_HPP
#define AVALIACAO_HPP

#include "super_dominio.hpp"

/**
 * @class Avaliacao
 * @brief Classe que representa uma avaliação com valor inteiro.
 * 
 * A classe `Avaliacao` deriva de `SuperDominio<int>` e implementa o método de validação
 * para garantir que o valor de uma avaliação seja válido de acordo com regras definidas.
 * 
 * Regras de validação devem ser implementadas no método `validar`.
 */
class Avaliacao : public SuperDominio<int>
{
private:
    /**
     * @brief Valida o valor da avaliação.
     * 
     * Implementa as regras de validação específicas para a classe `Avaliacao`. 
     * O valor de uma avaliação deve atender aos critérios definidos (ex.: faixa de valores permitida).
     * 
     * @param[in] valor Valor inteiro a ser validado.
     * @throws std::invalid_argument Caso o valor esteja fora das condições válidas.
     */
    void validar(int valor) override;
};

#endif // AVALIACAO_HPP
