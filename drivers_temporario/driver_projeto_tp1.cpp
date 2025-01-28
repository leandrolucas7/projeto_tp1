#include "../include/entidades/ENTIDADES.hpp"
#include "../include/dominios/DOMINIOS.hpp"
#include "../include/builder.hpp"
#include "../include/controladoresApr.hpp"
#include "../include/controladoresSer.hpp"
#include "../include/interfacesApr.hpp"
#include "../include/interfacesSer.hpp"

int main()
{
    BuilderSistema* builder = new BuilderSistema();
    CntrAprInicial* cntrAprInicial = builder->build_cntrAprInicial();
    cntrAprInicial->executar();
    delete builder;
    return 0;
}