#include "../../include/dominios/DOMINIOS.hpp"
#include <string>
#include <stdexcept>

void Dinheiro::validar(double v)
{
    int novo_valor = static_cast<int>(v * 100);
    if ((novo_valor >= 0 && novo_valor <= 20000000) && (v * 100 - novo_valor == 0))
        return;
    //throw invalid_argument("Argumento (" + to_string(v) + ") inválido.");
    throw invalid_argument("O dinheiro deve ser um numero de 0 a 200000, com ate 2 digitos depois do ponto, que age como separador decimal.");
}

