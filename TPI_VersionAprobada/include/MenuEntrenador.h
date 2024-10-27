#pragma once

#include "MenuPrincipal.h"

class MenuEntrenador
{
public:

    MenuEntrenador(UsuarioAutenticado usuario);

    void mostrarMenuEntrenador();
    void verHorariosYSociosAsignados();
    void crearModificarRutina();
    void verReclamos();
    void modificarContrasenia();

private:

    UsuarioAutenticado _usuario;
};
