#include "../../include/dominios/DOMINIOS.hpp"
#include "../../include/dominios/testes/TESTES.hpp"

void TesteData::set_valores()
{
    dominio = new Data();
    valores_validos = {"16-12-24","29-09-16","31-01-23","01-05-00"};
    valores_invalidos = {"31-04-10","12-00-90","12/07/13","00-05-00"};
}