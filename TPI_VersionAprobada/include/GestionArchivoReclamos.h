#pragma once

#include "Reclamo.h"

class GestionArchivoReclamos
{
    public:

        GestionArchivoReclamos();
        GestionArchivoReclamos(std::string nombreArchivo);

        bool guardarReclamo(Reclamo reclamo);
        bool guardarReclamo(Reclamo reclamo, int posicion);
        int buscarReclamo(int idReclamo);
        Reclamo leerRegistroReclamo(int posicion);
        int cantidadRegistrosReclamos();
        void leerRegistrosReclamo(int cantidadRegistros, Reclamo *vecReclamo);

        int cantidadDeRegistrosPorUsuario(int cantidadRegistros, int idUsuario);
        int leerRegistrosPorUsuario(int cantidadRegistros, int vectReclamos[], int tam, int idUsuario);


    private:

        std::string _nombreArchivo;
};
