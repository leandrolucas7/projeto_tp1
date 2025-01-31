#ifndef container_HPP
#define container_HPP

#include "./interfacesApr.hpp"
#include "./interfacesSer.hpp"
#include "dominios/DOMINIOS.hpp"
#include "entidades/ENTIDADES.hpp"
#include <list>

class ContainerContas;
class ContainerViagens;
class ContainerDestinos;
class ContainerHospedagens;
class ContainerAtividades;



class ContainerContas
{
    private:
        static ContainerContas* instancia;
        ContainerContas() {}
        ~ContainerContas();
        ContainerContas(const ContainerContas&) = delete;
        ContainerContas& operator=(const ContainerContas&) = delete;
        list<Conta*> container;
    public:
        static ContainerContas* get_instancia();
        static void delete_instancia();
        bool create(Conta*&);
        void destroy(Conta*&);
        bool fetch(Conta*&);
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

class ContainerDestinos
{
    private:
        static ContainerDestinos* instancia;
        ContainerDestinos() {}
        ~ContainerDestinos();
        ContainerDestinos(const ContainerDestinos&) = delete;
        ContainerDestinos& operator=(const ContainerDestinos&) = delete;
        list<Destino*> container;
    public:
        static ContainerDestinos* get_instancia();
        static void delete_instancia();
        bool create(Destino*&);
        void destroy(Destino*&);
};

class ContainerHospedagens
{
    private:
        static ContainerHospedagens* instancia;
        ContainerHospedagens() {}
        ~ContainerHospedagens();
        ContainerHospedagens(const ContainerHospedagens&) = delete;
        ContainerHospedagens& operator=(const ContainerHospedagens&) = delete;
        list<Hospedagem*> container;
    public:
        static ContainerHospedagens* get_instancia();
        static void delete_instancia();
        bool create(Hospedagem*&);
        void destroy(Hospedagem*&);
};

class ContainerAtividades
{
    private:
        static ContainerAtividades* instancia;
        ContainerAtividades() {}
        ~ContainerAtividades();
        ContainerAtividades(const ContainerAtividades&) = delete;
        ContainerAtividades& operator=(const ContainerAtividades&) = delete;
        list<Atividade*> container;
    public:
        static ContainerAtividades* get_instancia();
        static void delete_instancia();
        bool create(Atividade*&);
        void destroy(Atividade*&);
};


#endif