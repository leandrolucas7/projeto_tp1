#include "../include/controladoresSer.hpp"

bool CntrSerCUDConta::create(Conta* conta,Codigo codigo, Senha senha)
{
    conta->set_codigo(codigo);
    conta->set_senha(senha);
    ContainerContas* container = ContainerContas::get_instancia();
    bool resultado = container->add_conta(conta);
    return resultado;
}

void CntrSerCUDConta::update(Conta* conta, Codigo codigo, Senha senha)
{
    conta->set_codigo(codigo);
    conta->set_senha(senha);
}

void CntrSerCUDConta::destroy(Conta* conta_ptr)
{
    ContainerContas* container = ContainerContas::get_instancia();
    container->remove_conta(conta_ptr);
}



void CntrSerCUDViagem::create(Conta* conta, Codigo codigo, Nome nome, Avaliacao avaliacao)
{
    Viagem* viagem_ptr;
    viagem_ptr = new Viagem();
    viagem_ptr->set_codigo(codigo);
    viagem_ptr->set_nome(nome);
    viagem_ptr->set_avaliacao(avaliacao);
    conta->add_viagem(viagem_ptr);
}

void CntrSerCUDViagem::update(Viagem* viagem, Nome nome, Avaliacao avaliacao)
{
    viagem->set_nome(nome);
    viagem->set_avaliacao(avaliacao);
}

void CntrSerCUDViagem::destroy(Conta* conta, Viagem* viagem)
{
    conta->remove_viagem(viagem->get_codigo());
}


void CntrSerCUDDestino::create(Viagem* viagem, Codigo codigo, Nome nome, Data data_inicio, Data data_fim, Avaliacao avaliacao)
{
    Destino* destino_ptr;
    destino_ptr = new Destino();
    destino_ptr->set_codigo(codigo);
    destino_ptr->set_nome(nome);
    destino_ptr->set_data_inicio(data_inicio);
    destino_ptr->set_data_termino(data_fim);
    destino_ptr->set_avaliacao(avaliacao);
    viagem->add_destino(destino_ptr);
}

void CntrSerCUDDestino::update(Destino* destino, Nome nome, Data data_inicio, Data data_fim, Avaliacao avaliacao)
{
    destino->set_nome(nome);
    destino->set_data_inicio(data_inicio);
    destino->set_data_termino(data_fim);
    destino->set_avaliacao(avaliacao);
}

void CntrSerCUDDestino::destroy(Viagem* viagem, Destino* destino)
{
    viagem->remove_destino(destino->get_codigo());
}

void CntrSerCUDHospedagem::create(Destino* destino, Codigo codigo, Nome nome, Dinheiro diaria, Avaliacao avaliacao)
{
    Hospedagem* hospedagem_ptr;
    hospedagem_ptr = new Hospedagem();
    hospedagem_ptr->set_codigo(codigo);
    hospedagem_ptr->set_nome(nome);
    hospedagem_ptr->set_diaria(diaria);
    hospedagem_ptr->set_avaliacao(avaliacao);
    destino->add_hospedagem(hospedagem_ptr);
}

void CntrSerCUDHospedagem::update(Hospedagem* hospedagem, Nome nome, Dinheiro diaria, Avaliacao avaliacao)
{
    hospedagem->set_nome(nome);
    hospedagem->set_diaria(diaria);
    hospedagem->set_avaliacao(avaliacao);
}

void CntrSerCUDHospedagem::destroy(Destino* destino, Hospedagem* hospedagem)
{
    destino->remove_hospedagem(hospedagem->get_codigo());
}

void CntrSerCUDAtividade::create(Destino* destino, Codigo codigo, Nome nome, Data data, Horario horario, Duracao duracao, Dinheiro preco, Avaliacao avaliacao)
{
    Atividade* atividade_ptr;
    atividade_ptr = new Atividade();
    atividade_ptr->set_codigo(codigo);
    atividade_ptr->set_nome(nome);
    atividade_ptr->set_data(data);
    atividade_ptr->set_horario(horario);
    atividade_ptr->set_duracao(duracao);
    atividade_ptr->set_preco(preco);
    atividade_ptr->set_avaliacao(avaliacao);
    destino->add_atividade(atividade_ptr);
}

void CntrSerCUDAtividade::update(Atividade* atividade, Nome nome, Data data, Horario horario, Duracao duracao, Dinheiro preco, Avaliacao avaliacao)
{
    atividade->set_nome(nome);
    atividade->set_data(data);
    atividade->set_horario(horario);
    atividade->set_duracao(duracao);
    atividade->set_preco(preco);
    atividade->set_avaliacao(avaliacao);
}

void CntrSerCUDAtividade::destroy(Destino* destino, Atividade* atividade)
{
    destino->remove_atividade(atividade->get_codigo());
}