#pragma once

#include "RegistroAsistencia.h"


class GestionArchivoAsistencias
{
    public:
        GestionArchivoAsistencias();

        GestionArchivoAsistencias(std::string nombreArchivo);

        bool guardarAsistencia(RegistroAsistencia Asistencia);
        bool guardarAsistencia(RegistroAsistencia Asistencia, int posicion);
        int buscarAsistencia(int idSocio);
        RegistroAsistencia leerRegistroAsistencia(int posicion);
        int cantidadRegistrosAsistencias();
        void leerRegistrosAsistencia(int cantidadRegistros, RegistroAsistencia *vecAsistencia);


    private:

        std::string _nombreArchivo;
};
