#include "../../include/entidades/destino.hpp"


int Destino::get_atividade_index(Codigo atividade_id)
{
    for (int i = 0; i < atividades_ptr.size(); i++)
    {
        if (atividades_ptr[i]->get_codigo() == atividade_id)
        {
            return i;
        }
    }
    return -1;
}



Atividade* Destino::get_atividade_ptr(Codigo atividade_id)
{
    int index = get_atividade_index(atividade_id);
    if (index == -1)
    {
        return nullptr;
    }
    return atividades_ptr[index];
}


void Destino::add_atividade(Atividade* atividade)
{
    atividade->set_destino_id(codigo);
    atividades_ptr.push_back(atividade);
}

void Destino::remove_atividade(Codigo atividade_id)
{
    int index = get_atividade_index(atividade_id);
    atividades_ptr.erase(atividades_ptr.begin() + index);
}

int Destino::get_hospedagem_index(Codigo hospedagem_id)
{
    for (int i = 0; i < hospedagens_ptr.size(); i++)
    {
        if (hospedagens_ptr[i]->get_codigo() == hospedagem_id)
        {
            return i;
        }
    }
    return -1;
}



Hospedagem* Destino::get_hospedagem_ptr(Codigo hospedagem_id)
{
    int index = get_hospedagem_index(hospedagem_id);
    if (index == -1)
    {
        return nullptr;
    }
    return hospedagens_ptr[index];
}

void Destino::add_hospedagem(Hospedagem* hospedagem)
{
    hospedagem->set_destino_id(codigo);
    hospedagens_ptr.push_back(hospedagem);
}


void Destino::remove_hospedagem(Codigo hospedagem_id)
{
    int index = get_hospedagem_index(hospedagem_id);
    hospedagens_ptr.erase(hospedagens_ptr.begin() + index);
}