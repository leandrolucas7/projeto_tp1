#include "../../include/dominios/DOMINIOS.hpp"
#include "../../include/testes/TESTES.hpp"

void TesteDuracao::set_valores()
{
    dominio = new Duracao();
    valores_validos = {360, 1, 68, 34};
    valores_invalidos = {-1,365,600,-839};
}