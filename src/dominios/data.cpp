#include "../../include/dominios/DOMINIOS.hpp"
#include <string>
#include <cctype> // isalnum()
#include <stdexcept>


void Data::validar(string v) 
{
    int dia, mes, ano;
    bool flag = true;
    if (v.length() != 8) 
        flag = false;
    if (v[2] != '-' || v[5] != '-') 
        flag = false;
    for (int i = 0; i < 8; i++) 
    {
        if (i == 2 || i == 5) 
            continue;
        if (!isdigit(v[i])) 
            flag = false;
    }
    dia = stoi(v.substr(0, 2));
    mes = stoi(v.substr(3, 2));
    ano = stoi(v.substr(6, 2));
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 0 || ano > 99) 
        flag = false;
    // dias que não podem ocorrer
    if (mes == 2 && dia > 29) 
        flag = false;
    if (mes == 2 && dia == 29 && ano % 4 != 0) 
        flag =  false; 
    if (dia == 31 && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) 
        flag = false;
    if (flag)
        return;
    throw invalid_argument("Argumento (" + v + ") inválido.");
}


