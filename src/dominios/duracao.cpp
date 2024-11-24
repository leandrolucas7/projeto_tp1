#include "../../include/dominios/DOMINIOS.hpp"
#include <string>
#include <stdexcept>

using namespace std;

void Duracao::validar(int v)
{
    if (v >= 0 && v <= 360)
        return;
    throw invalid_argument("Argumento (" + to_string(v) + ") inválido.");
}

