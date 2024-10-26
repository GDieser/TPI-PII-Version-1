#pragma once

#include "MenuPrincipal.h"

class MenuGerente : public MenuPrincipal
{
public:

    MenuGerente();

    MenuGerente(int idGerente);

    void mostrarMenuGerente();
    void gestionarSocios();
    void gestionarEntrenadores();
    void gestionarGerentes();
    void gestionarPagos();
    void gestionarReclamos();
    void verEstadisticas();
    void modificarContrasenia();

private:

    int _idGerenete;

};
