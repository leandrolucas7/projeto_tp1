// Matrícula: 222025852
/**
 * @file SuperDominio.hpp
 * @brief Declaração da classe base genérica `SuperDominio`, utilizada como modelo para classes de domínio.
 * 
 * A classe `SuperDominio` é um template abstrato que define a interface básica para classes de domínio.
 * Cada classe derivada deve implementar o método de validação específico para o tipo de valor utilizado.
 * 
 * @tparam T Tipo do valor armazenado e validado pela classe.
 */

#ifndef SUPER_DOMINIO_HPP
#define SUPER_DOMINIO_HPP

/**
 * @class SuperDominio
 * @brief Classe base abstrata para definição de domínios genéricos.
 * 
 * A `SuperDominio` fornece métodos para armazenar, recuperar e validar valores. 
 * É necessário que classes derivadas implementem o método de validação específico para o tipo de dado usado.
 * 
 * @tparam T Tipo do valor que será manipulado pela classe.
 */
template <typename T>
class SuperDominio
{
protected:
    /**
     * @brief Valor armazenado pelo domínio.
     */
    T valor;

    /**
     * @brief Método abstrato para validação do valor.
     * 
     * Deve ser implementado nas classes derivadas para verificar se o valor fornecido atende 
     * às regras de negócio ou restrições definidas.
     * 
     * @param[in] valor Valor a ser validado.
     * @throws std::exception Caso o valor não seja válido.
     */
    virtual void validar(T valor) = 0;

public:
    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~SuperDominio() = default;

    /**
     * @brief Define o valor do domínio após validação.
     * 
     * Verifica a validade do valor fornecido antes de armazená-lo no domínio.
     * 
     * @param[in] valor Valor a ser atribuído.
     * @return true Se o valor foi atribuído com sucesso.
     * @return false Se a validação falhou (não altera o valor armazenado).
     */
    bool set_valor(T valor);

    /**
     * @brief Recupera o valor armazenado no domínio.
     * 
     * @return T Valor atualmente armazenado no domínio.
     */
    T get_valor() const;
};

template <typename T>
inline T SuperDominio<T>::get_valor() const
{
    return this->valor;
}

#endif // SUPER_DOMINIO_HPP
