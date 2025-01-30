#include "../../include/dominios/DOMINIOS.hpp"
#include <string>
#include <regex>
#include <stdexcept>

using namespace std;

void Horario::validar(string v)
{
    regex padrao_horario(R"(^(?:[01]\d|2[0-3]):[0-5]\d$)");
    if (regex_match(v, padrao_horario))
        return;
    //throw invalid_argument("Argumento (" + v + ") inválido.");
    throw invalid_argument("O horario deve estar no formato HH:MM");
}

