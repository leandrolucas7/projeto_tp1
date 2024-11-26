#include "../../include/dominios/DOMINIOS.hpp"
#include <cctype> // isalnum()
#include <regex>
#include <stdexcept>

void Nome::validar(string v)
{
    if (v.length() > 0 && v.length() <= 30)
        return;
    throw invalid_argument("Argumento (" + v + ") inválido.");
}

