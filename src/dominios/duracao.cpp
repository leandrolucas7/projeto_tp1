#include "../../include/dominios/DOMINIOS.hpp"
#include <string>
#include <stdexcept>

using namespace std;

void Duracao::validar(int v)
{
    if (v >= 0 && v <= 360)
        return;
    //throw invalid_argument("Argumento (" + to_string(v) + ") inválido.");
    throw invalid_argument("Formato invalido. A duracao deve ser um numero de 0 a 360");
}

