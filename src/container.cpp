#include "../include/container.hpp"
#include <iostream>
using namespace std;

//Implementacao dos singletons

ContainerContas* ContainerContas::instancia = nullptr;

ContainerContas* ContainerContas::get_instancia()
{
    if (instancia == nullptr)
    {
        instancia = new ContainerContas();
    }
    return instancia;
}

ContainerViagens* ContainerViagens::get_instancia()
{
    if (instancia == nullptr)
    {
        instancia = new ContainerViagens();
    }
    return instancia;
}

void ContainerContas::delete_instancia()
{
    delete instancia;
    instancia = nullptr;
}

void ContainerViagens::delete_instancia()
{
    delete instancia;
    instancia = nullptr;
}

ContainerContas::~ContainerContas()
{
    for (int i = 0; i < contas.size(); i++)
    {
        delete contas[i];
    }
}

ContainerViagens::~ContainerViagens()
{
    for (auto it = container.begin(); it != container.end(); it++)
    {
        delete *it;
    }
}

//Implementacao dos metodos CUD(create, update, delete)


bool ContainerContas::add_conta(Conta* &conta_ptr)
{
    for (int i = 0; i < contas.size(); i++)
    {
        if (contas[i]->get_codigo() == conta_ptr->get_codigo())
        {
            delete conta_ptr;
            conta_ptr = nullptr;
            return false;
        }
    }
    Conta* nova_conta = conta_ptr;
    contas.push_back(nova_conta);
    conta_ptr = nullptr;
    return true;
}

void ContainerContas::remove_conta(Conta* &conta_ptr)
{
    for (int i = 0; i < contas.size(); i++)
    {
        if (contas[i]->get_codigo()== conta_ptr->get_codigo())
        {
            contas.erase(contas.begin() + i);
            delete conta_ptr;
            conta_ptr = nullptr;
            break;
        }
    }
    conta_ptr = nullptr;
}

bool ContainerContas::fetch_conta(Conta* &conta_ptr)
{
    for (int i = 0; i < contas.size(); i++)
    {
        if (contas[i]->get_codigo() == conta_ptr->get_codigo() && contas[i]->get_senha() == conta_ptr->get_senha())
        {
            if (conta_ptr != nullptr)
                delete conta_ptr;
            conta_ptr = contas[i];
            return true;
        }
    }
    if (conta_ptr != nullptr)
        delete conta_ptr;
    conta_ptr = nullptr;
    return false;
}

bool ContainerViagens::create(Viagem* &ptr)
{
    for (auto it = container.begin(); it != container.end(); it++)
        {
            if ((*it)->get_codigo() == ptr->get_codigo())
                return false;
        }
    container.push_back(ptr);
    return true;
}

void ContainerViagens::destroy(Viagem* &ptr)
{
    for (auto it = container.begin(); it != container.end(); it++)
        {
            if ((*it)->get_codigo() == ptr->get_codigo())
                container.erase(it);
                delete ptr;
                ptr = nullptr;
                break;
        }
}
























