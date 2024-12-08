#include "../../../include/dominios/DOMINIOS.hpp"
#include "../../../include/dominios/testes/TESTES_DOMINIOS.hpp"

void TesteSenha::set_valores() 
{
    dominio = new Senha();
    valores_validos = {"12435", "54812", "20591", "04521", "45210"};
    valores_invalidos = {"01234", "02579", "54321", "97421", "11543", "58438", "12ab3", "11111"};
} 