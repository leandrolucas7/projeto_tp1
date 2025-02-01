#include "../../include/entidades/conta.hpp"

Conta::~Conta()
{
    for (int i = 0; i < static_cast<int>(this->viagens_ptr.size()); i++)
    {
        delete this->viagens_ptr[i];
    }
}

int Conta::get_viagem_index(Codigo viagem_id)
{
    for (int i = 0; i < static_cast<int>(this->viagens_ptr.size()); i++)
    {
        if ((this->viagens_ptr[i])->get_codigo() == viagem_id)
        {
            return i;
        }
    }
    return -1;
}

Viagem* Conta::get_viagem_ptr(Codigo viagem_id)
{
    int index = this->get_viagem_index(viagem_id);
    if (index == -1)
    {
        return nullptr;
    }
    return this->viagens_ptr[index];
}

void Conta::add_viagem(Viagem* viagem)
{
    viagem->set_conta_id(this->codigo);
    this->viagens_ptr.push_back(viagem);
}

void Conta::remove_viagem(Codigo viagem_id)
{
    int index = this->get_viagem_index(viagem_id);
    delete this->viagens_ptr[index];
    this->viagens_ptr.erase(this->viagens_ptr.begin() + index);
}




