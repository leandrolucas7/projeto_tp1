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
 * @brief Classe responsável pela validação de uma sequência de caracteres usada para autenticação.
 * 
 * A sequência de autenticação deve atender aos seguintes requisitos:
 *
 * - Contar com exatamente 5 dígitos numéricos.
 * - Não conter dígitos repetidos.
 * - Não estar em uma sequência crescente ou decrescente.
 * 
 * Caso algum desses requisitos não seja atendido, será lançada uma exceção do tipo `std::invalid_argument`.
 * 
 * @note Esta classe herda os métodos `set` e `get` da classe base `SuperDominio`.
 * 
 */

class Senha : public SuperDominio<string> 
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
    public:
        friend bool operator==(const Senha&, const Senha&);
};

#endif // SENHA_HPP
