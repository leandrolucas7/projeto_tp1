#include "../../include/dominios/DOMINIOS.hpp"
#include <regex>


bool Horario::validar(string v)
{
    std::regex padrao_horario(R"(^(?:[01]\d|2[0-3]):[0-5]\d$)");
    return std::regex_match(v, padrao_horario);
}

