#include "../../include/entidades/destino.hpp"
#include <stdexcept>

Destino::~Destino()
{
    for (int i = 0; i < static_cast<int>(atividades_ptr.size()); i++)
    {
        delete atividades_ptr[i];
    }
    for (int i = 0; i < static_cast<int>(hospedagens_ptr.size()); i++)
    {
        delete hospedagens_ptr[i];
    }
}

void Destino::set_data_termino(const Data &data_termino)
{   
    int dia_data_inicio = stoi(data_inicio.get_valor().substr(0, 2));
    int mes_data_inicio = stoi(data_inicio.get_valor().substr(3, 2));
    int ano_data_inicio = stoi(data_inicio.get_valor().substr(6, 2));
    int dia_data_termino = stoi(data_termino.get_valor().substr(0, 2));
    int mes_data_termino = stoi(data_termino.get_valor().substr(3, 2));
    int ano_data_termino = stoi(data_termino.get_valor().substr(6, 2));
    if(ano_data_termino < ano_data_inicio)
    {
        throw invalid_argument("Data de término inválida.");
    }
    else if (ano_data_termino == ano_data_inicio)
    {
        if (mes_data_termino < mes_data_inicio)
        {
            throw invalid_argument("Data de término inválida.");
        }
        else if(mes_data_termino == mes_data_inicio)
        {
            if(dia_data_termino < dia_data_inicio)
            {
                throw invalid_argument("Data de término inválida.");
            }
        }
    }
    this->data_termino = data_termino;
}


int Destino::get_atividade_index(Codigo atividade_id)
{
    for (int i = 0; i < static_cast<int>(atividades_ptr.size()); i++)
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
    for (int i = 0; i < static_cast<int>(hospedagens_ptr.size()); i++)
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
    delete this->hospedagens_ptr[index];
    hospedagens_ptr.erase(hospedagens_ptr.begin() + index);
}