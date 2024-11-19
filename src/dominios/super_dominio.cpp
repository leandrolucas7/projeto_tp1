#include <string>
#include "../../include/dominios/DOMINIOS.hpp"

template class SuperDominio<int>;
template class SuperDominio<std::string>;
template <typename T>
bool SuperDominio<T>::set_valor(T valor)
{
    if (!validar(valor))
        return false;
    this->valor = valor;
    return true;
}

