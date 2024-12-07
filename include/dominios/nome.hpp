// Matrícula: 232023969

/**
 * @file nome.hpp
 * @brief Declaração da classe 'Nome'.
 * 
 * Este arquivo define a classe `Nome`, que valida um título com base em critérios específicos.
 * 
 */

#ifndef NOME_HPP
#define NOME_HPP

#include "super_dominio.hpp"
#include <string>
using namespace std;

/**
 * @brief Classe responsável pela validação de uma sequência de caracteres usada para autenticação.
 * 
 * A sequência de autenticação deve atender aos seguintes requisitos:
 *
 * - Texto com até 30 caracteres.
 * 
 * Caso algum desses requisitos não seja atendido, será lançada uma exceção do tipo `std::invalid_argument`.
 * 
 * @note Esta classe herda os métodos `set` e `get` da classe base `SuperDominio`.
 * 
 */

class Nome: public SuperDominio<string>
{
    private:
    /**
     * @brief Valida a sequência fornecida conforme os critérios especificados.
     * 
     * Este método verifica se a sequência de autenticação atende aos requisitos de validade.
     * 
     * @param T String representando a sequência a ser validada.
     * 
     * @throw std::invalid_argument Se a sequência não atender aos critérios.
     */

        void validar(string) override;
};


#endif // SENHA_HPP
