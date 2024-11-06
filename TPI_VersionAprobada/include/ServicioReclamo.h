#pragma once

#include "GestionArchivoReclamos.h"

class ServicioReclamo
{
    public:
        ServicioReclamo();

        void cargarReclamo(int idUsuario);
        void mostrarReclamo(bool resuelto);
        void verReclamosUsuario(int idUsuario);
        void cambiarEstadoReclamo();
        int obtenerUltimoIdReclamo();

    private:

        GestionArchivoReclamos _archivoReclamos;
};

