#pragma once

#include "Empleado.h"

class GestionArchivoEmpleados
{
public:

    GestionArchivoEmpleados();

    GestionArchivoEmpleados(std::string nombreArchivo);

    bool guardarEmpleado(Empleado empleado);
    bool guardarEmpleado(Empleado empleado, int posicion);
    int buscarEmpleado(int idEmpleado);
    Empleado leerRegistroEmpleado(int posicion);
    int cantidadRegistrosEmpleados();
    void leerRegistrosEmpleados(int cantidadRegistros, Empleado *vectEmpleado);


private:
    std::string _nombreArchivo;
};


