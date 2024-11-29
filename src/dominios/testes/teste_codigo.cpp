#include "../../include/dominios/DOMINIOS.hpp"
#include "../../include/testes/TESTES.hpp"
#include <string>

void TesteCodigo::set_valores()
{
    dominio = new Codigo;
    valores_validos = {"A1b2C3", "aAbBcC", "123456", "unb100"};
    valores_invalidos = {"1234567", "a$bcde", "abc", "df.23ab", "df1$$$"};
}
