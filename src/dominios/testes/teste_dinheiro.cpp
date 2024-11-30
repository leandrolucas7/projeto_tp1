#include "../../../include/dominios/DOMINIOS.hpp"
#include "../../../include/dominios/testes/TESTES_DOMINIOS.hpp"

void TesteDinheiro::set_valores()
{
    dominio = new Dinheiro();
    valores_validos = {0.00, 2000, 50};
    valores_invalidos = {12.897, 300.456 , 3000000000};
}