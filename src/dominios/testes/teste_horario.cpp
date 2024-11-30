#include "../../../include/dominios/DOMINIOS.hpp"
#include "../../../include/dominios/testes/TESTES_DOMINIOS.hpp"

void TesteHorario::set_valores()
{
    dominio = new Horario();
    valores_validos = {"00:15", "14:30", "23:59"};
    valores_invalidos = {"24:00", "-02", "abc", "31:00", "12-00", "duas:trinta", "13:234"};
}
