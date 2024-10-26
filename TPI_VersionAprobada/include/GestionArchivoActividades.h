#pragma once

#include "Actividad.h"

class GestionArchivoActividades
{
public:
    GestionArchivoActividades();

    GestionArchivoActividades(std::string nombreArchivo);

    bool guardarActividad(Actividad actividad);
    bool guardarActividad(Actividad actividad, int posicion);
    int buscarActividad(int idActividad);
    Actividad leerRegistroActividad(int posicion);
    int cantidadRegistrosActividades();
    void leerRegistrosActividades(int cantidadRegistros, Actividad *vecActividad);

private:

    std::string _nombreArchivo;
};

