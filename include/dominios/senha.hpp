// Matrícula: 232024572

/**
 * @file senha.hpp
 * @brief Declaração da classe 'Senha'.
 * 
 */

/// Declaração da classe Senha

#ifndef SENHA_HPP
#define SENHA_HPP

#include <string>
#include "super_dominio.hpp"

using namespace std;

/**
 * @class Senha
 * @brief Classe responsável por validar uma senha seguindo critérios específicos.
 * 
 * A senha deve atender aos seguintes critérios:
 * - Conter exatamente 5 dígitos.
 * - Não possuir dígitos repetidos.
 * - Não estar em ordem crescente ou decrescente.
 * 
 * Caso algum dos critérios não seja atendido, será lançada uma exceção do tipo `std::invalid_argument`.
 * 
 * @note Esta classe herda os métodos 'set' e 'get' da classe base 'SuperDominio'.
 * 
 */

class Senha : public SuperDominio<string> 
{
    private:
        /**
         * @brief Valida a senha fornecida.
         * 
         * Este método é utilizado internamente para verificar os critérios de validade da senha.
         * 
         * @param T String contendo a senha a ser validada.
         * 
         * @throw std::invalid_argument Se a senha for inválida.
         */
        void validar(string) override;
};

#endif // SENHA_HPP