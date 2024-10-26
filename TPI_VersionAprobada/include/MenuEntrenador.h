#pragma once

#include "MenuPrincipal.h"

class MenuEntrenador : public MenuPrincipal
{
public:
    MenuEntrenador();

    MenuEntrenador(int idEntrenador);

    void mostrarMenuEntrenador();
    void verHorariosYSociosAsignados();
    void crearModificarRutina();
    void verReclamos();
    void modificarContrasenia();

private:

    int _idEntrenador;
};
