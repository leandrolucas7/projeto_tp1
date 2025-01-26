//Matrícula: 232013004
/**
 * @file codigo.hpp
 * @brief Declaração da classe Codigo, derivada de SuperDominio.
 * 
 * 
 */

#ifndef CODIGO_HPP
#define CODIGO_HPP

#include "super_dominio.hpp"
#include <string>
using namespace std;

/**
 * @class Codigo
 * @brief Classe para validação de códigos específicos.
 * 
 * A classe `Codigo` é uma especialização de `SuperDominio` para o tipo `string`.
 * Contém um método privado para validar as strings.
 * 
 */
class Codigo: public SuperDominio<string>
{
    private:
        /**
         * @brief Valida um código fornecido.
         * 
         * Este método verifica se o código fornecido atende aos critérios específicos de validação.
         * Deve ser implementado para lançar exceções em caso de falha na validação.
         * 
         * O método de validação implementado posteriormente consiste em checar se os caracteres da string recebida são
         * números inteiros e se seu tamanho é igual a 6 caracteres.
         * 
         * @param codigo String que representa o código a ser validado.
         * @throws invalid_argument Caso o código não seja válido.
         */
        void validar(string codigo) override;
    public:
        friend bool operator==(const Codigo&, const Codigo&);
};

#endif
