// Matrícula: 232024572

/**
 * @file senha.hpp
 * @brief Declaração da classe 'Senha'.
 * 
 * Este arquivo define a classe `Senha`, que valida uma credencial com base em critérios específicos.
 * 
 */

#ifndef SENHA_HPP
#define SENHA_HPP

#include <string>
#include "super_dominio.hpp"

using namespace std;

/**
 * @brief Classe responsável pela validação de uma credencial de senha.
 * 
 * A senha deve cumprir os seguintes requisitos:
 * - Contar com exatamente 5 dígitos.
 * - Não possuir dígitos repetidos.
 * - Não estar em uma sequência crescente ou decrescente.
 * 
 * Caso algum desses requisitos não seja atendido, uma exceção do tipo `std::invalid_argument` será lançada.
 * 
 * @note Esta classe herda os métodos `set` e `get` da classe base `SuperDominio`.
 * 
 */

class Senha : public SuperDominio<string> 
{
    private:
        /**
         * @brief Valida a senha fornecida conforme os critérios especificados.
         * 
         * Este método verifica se a senha atende aos requisitos de validade.
         * 
         * @param T String representando a senha a ser validada.
         * 
         * @throw std::invalid_argument Se a senha não atender aos critérios.
         */
        void validar(string) override;
};

#endif // SENHA_HPP
