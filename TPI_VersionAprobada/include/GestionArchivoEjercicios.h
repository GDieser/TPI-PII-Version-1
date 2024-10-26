#pragma once

#include "Ejercicio.h"

class GestionArchivoEjercicios
{
public:

    GestionArchivoEjercicios();
    GestionArchivoEjercicios(std::string nombreArchivo);

    bool guardarEjercicio(Ejercicio ejercicio);
    bool guardarEjercicio(Ejercicio ejercicio, int posicion);
    int buscarEjercicio(int idEjercicio);
    Ejercicio leerRegistroEjercicio(int posicion);
    int cantidadRegistrosEjercicios();
    void leerRegistrosEjercicio(int cantidadRegistros, Ejercicio *vecEjercicio);


private:

    std::string _nombreArchivo;
};
