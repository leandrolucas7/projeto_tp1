//232023969

#ifndef ModSerAutenticacao_HPP
#define ModSerAutenticacao_HPP

#include "../../interfaces/servicos/int_ser_autenticacao.hpp"

/**
 * @brief Módulo de serviço responsável pela lógica de autenticação
 * 
 * Esta classe implementa a interface IntSerAutenticacao e fornece
 * os serviços necessários para validar as credenciais de um usuário
 * na camada de serviços do sistema.
 */
class ModSerAutenticacao : public IntSerAutenticacao
{
    public:
        /**
         * @brief Valida as credenciais de um usuário
         * 
         * @param conta Objeto Conta contendo as credenciais a serem validadas
         * @return true Se as credenciais forem válidas
         * @return false Se as credenciais forem inválidas
         */
        bool autenticar(Conta) override;
};

#endif // MOD_SER_AUTENTICACAO_HPP
