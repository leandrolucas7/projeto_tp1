#ifndef container_HPP
#define container_HPP

#include "./interfacesApr.hpp"
#include "./interfacesSer.hpp"
#include "dominios/DOMINIOS.hpp"
#include "entidades/ENTIDADES.hpp"
#include <list>

class ContainerContas
{
    private:
        static ContainerContas* instancia;
        ContainerContas() {}
        ~ContainerContas();
        ContainerContas(const ContainerContas&) = delete;
        ContainerContas& operator=(const ContainerContas&) = delete;
        vector<Conta*> contas;
    public:
        static ContainerContas* get_instancia();
        static void delete_instancia();
        bool add_conta(Conta*&);
        void remove_conta(Conta*&);
        bool fetch_conta(Conta*&);
};

class ContainerViagens
{
    private:
        static ContainerViagens* instancia;
        ContainerViagens() {}
        ~ContainerViagens();
        ContainerViagens(const ContainerViagens&) = delete;
        ContainerViagens& operator=(const ContainerViagens&) = delete;
        list<Viagem*> container;
    public:
        static ContainerViagens* get_instancia();
        static void delete_instancia();
        bool create(Viagem*&);
        void destroy(Viagem*&);
        //bool fetch(Viagem*&);
};


#endif