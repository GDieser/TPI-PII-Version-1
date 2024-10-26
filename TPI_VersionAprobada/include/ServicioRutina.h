#pragma once

#include "GestionArchivoDetalleRutinas.h"
#include "GestionArchivoRutinas.h"
#include "DetalleRutina.h"

class ServicioRutina
{
    public:
        ServicioRutina();

        void verRutinas(int idEntrenador);
        void crearRutina(int idEntrenador);
        void modificarRutina(int idEntrenador);
        void asignarRutina();

        ///Necesitamos para los detalles de rutinas, se crean a la vez que una nueva rutina pero se
        ///manejan con diferentes registros
        int obtenerUltimoIdRutina();
        DetalleRutina crearDetalleRutina(int idRutina);
        void verDetallesDeRutina();

    private:

        GestionArchivoDetalleRutinas _archivoDetallesRutina;
        GestionArchivoRutinas _archivoRutina;
};

