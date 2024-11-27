#include "../../include/dominios/DOMINIOS.hpp"
#include "../../include/testes/TESTES.hpp"

void TesteNome::set_valores()
{
    dominio = new Nome();
    valores_validos = {"16-12-24","29-09-16","31-01-23","00-05-00"};
    valores_invalidos = {"","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"};
}