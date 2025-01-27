#include <iostream>
#include <stdexcept>
#include <typeinfo>
#include <string>
#include <type_traits>
#include "../../../include/dominios/testes/super_teste.hpp"
#include "../../../include/utils/to_string_util.hpp"

using namespace std;


template <typename T>
void SuperTeste<T>::set_teste()
{
    //dominio = new SuperDominio<T>();
    estado = SUCESSO;
}

template <typename T>
void SuperTeste<T>::tear_down()
{
    delete dominio;
    dominio = nullptr;
}

template <typename T>
void SuperTeste<T>::testar_valores_validos()
{
    for (T valor : valores_validos)
    {
        try 
        {
            dominio->set_valor(valor);
            if (dominio->get_valor() != valor)
                estado = FALHA;
        }
        catch (invalid_argument &exp)
        {
            estado = FALHA;
        }

        if (estado == FALHA)
        {
            throw invalid_argument("FALHA: Argumento válido (" + to_string_custom(valor) + ") não validado");
        }
    }
}


template <typename T>
void SuperTeste<T>::testar_valores_invalidos()
{
    for (T valor : valores_invalidos)
    {
        try 
        {
            dominio->set_valor(valor);
            estado = FALHA;
        }
        catch (invalid_argument &exp)
        {
            if (dominio->get_valor() == valor)
                estado = FALHA;
        }

        if (estado == FALHA)
        {
            throw invalid_argument("FALHA: Argumento inválido (" + to_string_custom(valor) + ") validado");
        }
    }
}


template <typename T>
int SuperTeste<T>::run()
{
    set_valores();
    set_teste();
    try 
    {
        testar_valores_validos();
        testar_valores_invalidos();
    }
    catch (invalid_argument &exp)
    {
        cout << exp.what() << endl;
    }
    tear_down();
    return estado;
}


template class SuperTeste<int>;
template class SuperTeste<double>;
template class SuperTeste<std::string>;
