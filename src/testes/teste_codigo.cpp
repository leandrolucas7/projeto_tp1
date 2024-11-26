#include "../../include/dominios/DOMINIOS.hpp"
#include "../../include/testes/TESTES.hpp"
#include "teste_codigo.hpp"
#include <string>

void TesteCodigo::set_valores()
{
    dominio = new Codigo;
    valores_invalidos = {"1234567", "a$bcde", };

}