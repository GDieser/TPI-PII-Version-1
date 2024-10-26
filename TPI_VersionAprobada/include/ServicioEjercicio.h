#pragma once

#include "GestionArchivoEjercicios.h"

class ServicioEjercicio
{
    public:
        ServicioEjercicio();

        void verEjercicios();
        void agregarEjercicio();
        void modificarEjercicio();

        ///Para autonumerar los ID de Ejercicio
        int obtenerUltimoIdEjercicio();

    private:

        GestionArchivoEjercicios _archivoEjercicio;
};

