#pragma once

#include "MenuPrincipal.h"

class MenuSocio : public MenuPrincipal
{

public:

    MenuSocio();

    MenuSocio(int idSocio);

    void mostrarMenuSocio();
    ///deberia llamarse gestionar pagos
    void gestionarPagos();

    void verRutina();
    void consultarHorarios();
    void presentarReclamo();
    ///void modificarContrasenia(); //deberia estar en servicio

    ///Precios
    void mostrarPreciosDePases();
    ///Por defecto
    void verHorariosGimnasio();

private:

    int _idSocio;
};
