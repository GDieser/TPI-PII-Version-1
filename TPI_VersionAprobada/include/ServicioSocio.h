#pragma once

#include "GestionArchivoSocios.h"
#include "GestionArchivoEmpleados.h"

class ServicioSocio
{
public:

    ServicioSocio();

    void verSocios();
    void agregarSocio();
    void modificarSocio(int idSocio);
    void verEntrenadorAsignado(int idSocio);
    void verHorarios();
    void verMembresia(int idSocio);
    void modificarContrasenia(int idSocio);
    // Agregados como metodos auxiliares
    int autoGenerarId();
    std::string membresiaToStr(int idMemb);
    int seleccionarMembresia();
    void mostrarTurno(int idTurno);

private:

    GestionArchivoSocios  _archivoSocio;
    GestionArchivoEmpleados _archivoEmpleado;
};


