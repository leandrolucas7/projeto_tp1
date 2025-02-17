#include "../../include/entidades/viagem.hpp"

Viagem::~Viagem()
{
    for (int i = 0; i < static_cast<int>(this->destinos_ptr.size()); i++)
    {
        delete this->destinos_ptr[i];
    }
}


int Viagem::get_destino_index(Codigo destino_id)
{
    for (int i = 0; i < static_cast<int>(this->destinos_ptr.size()); i++)
    {
        if ((this->destinos_ptr[i])->get_codigo() == destino_id)
        {
            return i;
        }
    }
    return -1;
}

Destino** Viagem::get_destino_ptr(Codigo destino_id)
{
    int index = this->get_destino_index(destino_id);
    if (index == -1)
    {
        return nullptr;
    }
    return &(this->destinos_ptr[index]);
}

void Viagem::add_destino(Destino* &destino)
{
    destino->set_viagem_id(this->codigo);
    this->destinos_ptr.push_back(destino);
}

void Viagem::remove_destino(Codigo destino_id)
{
    int index = this->get_destino_index(destino_id);
    delete this->destinos_ptr[index];
    this->destinos_ptr.erase(this->destinos_ptr.begin() + index);
}

void Viagem::remove_null_pointers()
{
    for (int i = 0; i < static_cast<int>(this->destinos_ptr.size()); i++)
    {
        if (this->destinos_ptr[i] == nullptr)
        {
            this->destinos_ptr.erase(this->destinos_ptr.begin() + i);
            break;
        }
    }
}

