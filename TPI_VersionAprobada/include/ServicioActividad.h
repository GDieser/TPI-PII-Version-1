#pragma once

#include "GestionArchivoActividades.h"

class ServicioActividad
{
public:
    ServicioActividad();

    void listarActividades();
    int agregarActividad();
    void modificarActividad();

    void buscarActividad(int idActividad);


private:

    GestionArchivoActividades _archivoActividad;
};


