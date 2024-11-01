#pragma once

#include "GestionArchivoEjercicios.h"

class ServicioEjercicio
{
    public:
        ServicioEjercicio();

        void verEjercicios();
        void agregarEjercicio();
        void modificarEjercicio();
        int obtenerUltimoIdEjercicio();

    private:

        GestionArchivoEjercicios _archivoEjercicio;
};

