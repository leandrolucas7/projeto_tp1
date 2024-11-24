#include "../../include/dominios/DOMINIOS.hpp"
#include <cctype> // isalnum()
#include <regex>


void Data::validar(string v) 
{
   /* int dia, mes, ano;
    if (v.length() != 8) 
        return false;
    if (v[2] != '-' || v[5] != '-') 
        return false;
    for (int i = 0; i < 8; i++) 
    {
        if (i == 2 || i == 5) 
            continue;
        if (!isdigit(v[i])) 
            return false;
    }
    dia = stoi(v.substr(0, 2));
    mes = stoi(v.substr(3, 2));
    ano = stoi(v.substr(6, 2));
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 0 || ano > 99) 
        return false;
    // dias que não podem ocorrer
    if (mes == 2 && dia == 29 && ano % 4 != 0) 
        return false; 
    if (mes == 2 && dia > 29) 
        return false;
    if (dia == 31 && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) 
        return false;
    return true;*/
}

bool Data::set_valor(string v) 
{
    //if (!validar(v))
    //    return false;
    valor = v;
    return true;
}

