#pragma once

#include "GestionArchivoDetalleRutinas.h"
#include "GestionArchivoRutinas.h"
#include "DetalleRutina.h"

class ServicioRutina
{
    public:
        ServicioRutina();

        void verRutinas(int idEntrenador);
        void verRutinaAsignada(int idSocio);
        void crearRutina(int idEntrenador);
        void mostrarOpcionesModificarRutina(int idEntrenador);
        void asignarRutina();
        void verDetallesDeRutina();
        void mostrarRutinasPorEntrenador(int idEntrenador);
        int obtenerUltimoIdRutina();
        DetalleRutina crearDetalleRutina(int idRutina);
        void buscarRutina();

        Rutina modificarRutina(Rutina rutina);
        DetalleRutina modificarDetalleRutina(DetalleRutina detalle);

        int elegirRutina(int idEntrenador);

    private:

        GestionArchivoDetalleRutinas _archivoDetallesRutina;
        GestionArchivoRutinas _archivoRutina;
};

