#include "../../include/dominios/DOMINIOS.hpp"
#include <cctype> // isalnum()
#include <regex>

void Nome::validar(string v)
{
    // O nome precisa ter apenas letras???
    /*if (v.length() > 0 && v.length() <= 30)
        return true;
    return false;*/
}

bool Nome::set_valor(string v)
{
    //if (!validar(v))
    //    return false;
    valor = v;
    return true;
}
