#pragma once

#include "GestionArchivoSocios.h"

class ServicioSocio
{
public:

    ServicioSocio();

    void verSocios();
    void agregarSocio();
    void modificarSocio();
    void verEntrenadorAsignado(int idSocio);
    void verHorarios();
    void verMembresia(int idSocio);
    void modificarContrasenia(int idSocio);

    int obternerUltimoIdSocio();

    ///Adicional
    void mostrarSociosPorEntrenador(int idEntrenador);

private:

    GestionArchivoSocios  _archivoSocio;
};


