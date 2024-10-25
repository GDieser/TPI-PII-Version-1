#pragma once

#include "GestionArchivoAsistencias.h"

class ServicioAsistencia
{
    public:
        ServicioAsistencia();


        bool validarRegistroDeAsistencia(int idSocio, Fecha fechaActual);

        void registrarAsistencia(int idSocio);
        void verAsistenciaPorSocio(int idSocio);

    private:

        GestionArchivoAsistencias _archivoAsitencia;
};

