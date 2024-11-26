#include "../../include/dominios/DOMINIOS.hpp"
#include <string>
#include <cctype> // isalnum()
#include <stdexcept>


void Data::validar(string v) 
{
    int dia, mes, ano;
    if (v.length() != 8) 
        throw invalid_argument("Argumento (" + v + ") inválido.");
    if (v[2] != '-' || v[5] != '-') 
        throw invalid_argument("Argumento (" + v + ") inválido.");
    for (int i = 0; i < 8; i++) 
    {
        if (i == 2 || i == 5) 
            continue;
        if (!isdigit(v[i])) 
            throw invalid_argument("Argumento (" + v + ") inválido.");
    }
    dia = stoi(v.substr(0, 2));
    mes = stoi(v.substr(3, 2));
    ano = stoi(v.substr(6, 2));
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 0 || ano > 99) 
        throw invalid_argument("Argumento (" + v + ") inválido.");
    // dias que não podem ocorrer
    if (mes == 2 && dia > 29) 
        throw invalid_argument("Argumento (" + v + ") inválido.");
    if (mes == 2 && dia == 29 && ano % 4 != 0) 
        throw invalid_argument("Argumento (" + v + ") inválido."); 
    if (dia == 31 && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) 
        throw invalid_argument("Argumento (" + v + ") inválido.");
}


