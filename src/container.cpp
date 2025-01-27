#include "../include/container.hpp"

ContainerContas* ContainerContas::instancia = nullptr;

ContainerContas* ContainerContas::get_instancia()
{
    if (instancia == nullptr)
    {
        instancia = new ContainerContas();
    }
    return instancia;
}

void ContainerContas::delete_instancia()
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


bool ContainerContas::add_conta(Conta* conta_ptr)
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
    Conta* nova_conta = new Conta();
    nova_conta->set_codigo(conta_ptr->get_codigo());
    nova_conta->set_senha(conta_ptr->get_senha());
    contas.push_back(nova_conta);
    delete conta_ptr;
    conta_ptr = nullptr;
    return true;
}

void ContainerContas::remove_conta(Conta* conta_ptr)
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

bool ContainerContas::fetch_conta(Conta* conta_ptr)
{
    for (int i = 0; i < contas.size(); i++)
    {
        if (contas[i]->get_codigo() == conta_ptr->get_codigo() && contas[i]->get_senha() == conta_ptr->get_senha())
        {
            conta_ptr = contas[i];
            return true;
        }
    }
    delete conta_ptr;
    conta_ptr = nullptr;
    return false;
}