#include "../../../include/dominios/DOMINIOS.hpp"
#include "../../../include/dominios/testes/TESTES_DOMINIOS.hpp"

void TesteAvaliacao::set_valores()
{
    dominio = new Avaliacao();
    valores_validos = {0, 1, 2, 3, 4, 5};
    valores_invalidos = {-100, -1, 6, 100};
}
