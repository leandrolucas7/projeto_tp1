#include "../../include/dominios/DOMINIOS.hpp"
#include <string>
#include <stdexcept>

void Avaliacao::validar(int v)
{
    if (v >= 0 && v <= 5)
        return;
    //throw invalid_argument("Argumento (" + to_string(v) + ") inválido.");
    throw invalid_argument("Formato invalido. A avaliacao deve ser um digito de 1 a 5");
}

