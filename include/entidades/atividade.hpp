//Matrícula: 232006215

/**
 * @file atividade.hpp
 * @brief Declaração da classe `Atividade`.
 * 
 * Este arquivo define a classe `Atividade`, que armazena informações inerentes ao serviço fornecido ao usuário em um certo destino.
 * 
 */



#ifndef ATIVIDADE_HPP_INCLUDED
#define ATIVIDADE_HPP_INCLUDED

#include "../dominios/DOMINIOS.hpp"

using namespace std;

/**
 * @class Atividade
 * @brief Classe que armazena informações relativas a um serviço provido ao usuário durante uma viagem0, em determinado destino, tais quais a data, horário, duração, preço e uma avaliação do serviço prestado.
 */

class Atividade
{
    private:
        Codigo codigo; ///< Age como identificador do serviço prestado
        Codigo destino_id; ///< Age como identificador do destino associado ao serviço
        Nome nome;
        Data data;
        Horario horario;
        Duracao duracao;
        Dinheiro preco;
        Avaliacao avaliacao;
    public:
        /**
         * @brief Define uma identificação associada ao serviço fornecido.
         * @param codigo Referência constante para uma instância da classe `Codigo`.
         */
        void set_codigo(const Codigo&);
        /**
         * @brief Retorna a identificação atrelada ao serviço.
         * @return Instância de `Codigo` .
         */
        Codigo get_codigo() const;
        /**
         * @brief Define um identificador para o destino associado ao serviço.
         * @param destino_id Referência constante para uma instância da classe `Codigo`.
         */
        void set_destino_id(const Codigo&);
        /**
         * @brief Retorna o identificador do destino associado ao serviço.
         * @return Instância de `Codigo`.
         */
        Codigo get_destino_id() const;
        /**
         * @brief Define um rótulo para serviço fornecido.
         * @param nome Referência constante para uma instância da classe `Nome`.
         */
        void set_nome(const Nome&);
        /**
         * @brief Retorna o título do serviço.
         * @return Instância de `Nome` .
         */
        Nome get_nome() const;
        /**
         * @brief Define um marco temporal, em dia, mês e ano, para serviço fornecido.
         * @param data Referência constante para uma instância da classe `Data`.
         */
        void set_data(const Data&);
        /**
         * @brief Retorna o dia em que o serviço foi provido.
         * @return Instância de `Data`.
         */
        Data get_data() const;
        /**
         * @brief Define o momento do dia, em horas e minutos, em que o serviço ocorreu.
         * @param horario Referência constante para uma instância da classe `Horario`.
         */
        void set_horario(const Horario&);
        /**
         * @brief Retorna o horario de execução do serviço.
         * @return Instância de `Horario`.
         */
        Horario get_horario() const;
        /**
         * @brief Define o príodo de tempo durante o qual o serviço prolongou-se.
         * @param duracao Referência constante para uma instância da classe `Duracao`.
         */
        void set_duracao(const Duracao&);
        /**
         * @brief Retorna o período do serviço.
         * @return Instância de `Duracao`.
         */
        Duracao get_duracao() const;
        /**
         * @brief Define o custo do serviço.
         * @param preco Referência constante para uma instância da classe `Dinheiro`.
         */
        void set_preco(const Dinheiro&);
        /**
         * @brief Retorna o custo do serviço.
         * @return Instância de `Dinheiro`.
         */
        Dinheiro get_preco() const;
        /**
         * @brief Define uma pontuação para o serviço fornecido.
         * @param avaliacao Referência constante para uma instância da classe `Avaliacao`.
         */
        void set_avaliacao(const Avaliacao&);
        /**
         * @brief Retorna a nota de satisfação do serviço.
         * @return Instância de `Avaliacao`.
         */
        Avaliacao get_avaliacao() const;
};

inline void Atividade::set_codigo(const Codigo &codigo)
{
    this->codigo = codigo;
}

inline Codigo Atividade::get_codigo() const
{
    return codigo;
}

inline void Atividade::set_destino_id(const Codigo &destino_id)
{
    this->destino_id = destino_id;
}

inline Codigo Atividade::get_destino_id() const
{
    return destino_id;
}


inline void Atividade::set_nome(const Nome &nome)
{
    this->nome = nome;
}

inline Nome Atividade::get_nome() const
{
    return nome;
}

inline void Atividade::set_data(const Data &data)
{
    this->data = data;
}

inline Data Atividade::get_data() const
{
    return data;
}

inline void Atividade::set_horario(const Horario &horario)
{
    this->horario = horario;
}

inline Horario Atividade::get_horario() const
{
    return horario;
}

inline void Atividade::set_duracao(const Duracao &duracao)
{
    this->duracao = duracao;
}

inline Duracao Atividade::get_duracao() const
{
    return duracao;
}

inline void Atividade::set_preco(const Dinheiro &preco)
{
    this->preco = preco;
}

inline Dinheiro Atividade::get_preco() const
{
    return preco;
}

inline void Atividade::set_avaliacao(const Avaliacao &avaliacao)
{
    this->avaliacao = avaliacao;
}

inline Avaliacao Atividade::get_avaliacao() const
{
    return avaliacao;
}

#endif