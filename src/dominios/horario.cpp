#ifndef HORARIO_CPP
#define HORARIO_CPP

#include "../../include/dominios/DOMINIOS.hpp"
#include <cctype> // isalnum()
#include <regex>


bool Horario::validar(string v)
{
    std::regex padrao_horario(R"(^(?:[01]\d|2[0-3]):[0-5]\d$)");
    return std::regex_match(v, padrao_horario);
}

bool Horario::set_valor(string v)
{
    if (!validar(v))
        return false;
    valor = v;
    return true;
}

int Horario::get_hora() const
{ return stoi(valor.substr(0, 2)); }

int Horario::get_minutos() const
{ return stoi(valor.substr(3, 2)); }

#endif
