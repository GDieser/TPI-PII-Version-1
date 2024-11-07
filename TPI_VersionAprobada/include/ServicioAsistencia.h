#pragma once

#include "GestionArchivoAsistencias.h"

class ServicioAsistencia
{
    public:
        ServicioAsistencia();


        bool validarRegistroDeAsistencia(int idSocio, Fecha fechaActual);
        void verTodasLasAsistencia();
        void verAsistenciasEnPeriodo(int mes, int anio);
        void verAsistenciasEnAnio(int anio);
        void registrarAsistencia(int idSocio);
        void verAsistenciaPorSocio(int idSocio);
        void verAsistenciaPorSocioPorMes(int idSocio, int mes);
        void verAsistenciaPorSocioPorAnio(int idSocio, int anio);

    private:

        GestionArchivoAsistencias _archivoAsitencia;
};

