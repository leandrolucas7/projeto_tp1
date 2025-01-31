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

ContainerDestinos* ContainerDestinos::get_instancia()
{
    if (instancia == nullptr)
    {
        instancia = new ContainerDestinos();
    }
    return instancia;
}

ContainerHospedagens* ContainerHospedagens::get_instancia()
{
    if (instancia == nullptr)
    {
        instancia = new ContainerHospedagens();
    }
    return instancia;
}

ContainerAtividades* ContainerAtividades::get_instancia()
{
    if (instancia == nullptr)
    {
        instancia = new ContainerAtividades();
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

void ContainerViagens::delete_instancia()
{
    delete instancia;
    instancia = nullptr;
}

void ContainerHospedagens::delete_instancia()
{
    delete instancia;
    instancia = nullptr;
}

void ContainerAtividades::delete_instancia()
{
    delete instancia;
    instancia = nullptr;
}

ContainerContas::~ContainerContas()
{
    for (auto it = container.begin(); it != container.end() ;it++)
    {
        delete *it;
    }
}

ContainerViagens::~ContainerViagens()
{
    for (auto it = container.begin(); it != container.end(); it++)
    {
        delete *it;
    }
}

ContainerDestinos::~ContainerDestinos()
{
    for (auto it = container.begin(); it != container.end(); it++)
    {
        delete *it;
    }
}

ContainerHospedagens::~ContainerHospedagens()
{
    for (auto it = container.begin(); it != container.end(); it++)
    {
        delete *it;
    }
}

ContainerAtividades::~ContainerAtividades()
{
    for (auto it = container.begin(); it != container.end(); it++)
    {
        delete *it;
    }
}

//Implementacao dos metodos CUD(create, update, delete)

bool ContainerContas::create(Conta* &conta_ptr)
{
    for (auto it = container.begin(); it != container.end(); it++)
    {
        if ((*it)->get_codigo() == conta_ptr->get_codigo())
        {
            delete conta_ptr;
            conta_ptr = nullptr;
            return false;
        }
    }

    Conta* nova_conta = conta_ptr;
    container.push_back(nova_conta);
    conta_ptr = nullptr;
    return true;
}

void ContainerContas::destroy(Conta* &conta_ptr)
{
    for (auto it = container.begin(); it != container.end(); it++)
    {
        if ((*it)->get_codigo()== conta_ptr->get_codigo())
        {
            container.erase(it);
            delete conta_ptr;
            conta_ptr = nullptr;
            break;
        }
    }
    conta_ptr = nullptr;
}

bool ContainerContas::fetch(Conta* &conta_ptr)
{
    for (auto it = container.begin(); it != container.end();it++)
    {
        if ((*it)->get_codigo() == conta_ptr->get_codigo() && (*it)->get_senha() == conta_ptr->get_senha())
        {
            delete conta_ptr;
            conta_ptr = *it;
            return true;
        }
    }
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

bool ContainerDestinos::create(Destino* &ptr)
{
    for (auto it = container.begin(); it != container.end(); it++)
        {
            if ((*it)->get_codigo() == ptr->get_codigo())
                return false;
        }
    container.push_back(ptr);
    return true;
}

bool ContainerHospedagens::create(Hospedagem* &ptr)
{
    for (auto it = container.begin(); it != container.end(); it++)
        {
            if ((*it)->get_codigo() == ptr->get_codigo())
                return false;
        }
    container.push_back(ptr);
    return true;
}

bool ContainerAtividades::create(Atividade* &ptr)
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

void ContainerDestinos::destroy(Destino* &ptr)
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


void ContainerHospedagens::destroy(Hospedagem* &ptr)
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

void ContainerAtividades::destroy(Atividade* &ptr)
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





















