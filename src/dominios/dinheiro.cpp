#include "../../include/dominios/DOMINIOS.hpp"
#include <string>
#include <cmath>
#include <stdexcept>

void Dinheiro::validar(double v)
{
    if (v >= 0 && v <= 200000) {
        double novo_valor = v * 100;
        double arredondado = round(novo_valor);

        if (fabs(novo_valor - arredondado) < 1e-9) 
            return;
    }

    //throw invalid_argument("Argumento (" + to_string(v) + ") inválido.");
    throw invalid_argument("O dinheiro deve ser um numero de 0 a 200000, com ate 2 digitos depois do ponto, que age como separador decimal.");
}

