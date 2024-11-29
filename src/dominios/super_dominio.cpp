#include <string>
#include "../../include/dominios/DOMINIOS.hpp"

template class SuperDominio<int>;
template class SuperDominio<double>;
template class SuperDominio<std::string>;


template <typename T>
bool SuperDominio<T>::set_valor(T valor)
{
    validar(valor);
    this->valor = valor;
    return true;
}

