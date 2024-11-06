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
        void verEjercicio(int IdEjercicio);

    private:

        GestionArchivoEjercicios _archivoEjercicio;
};

