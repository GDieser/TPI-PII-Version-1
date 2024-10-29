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

    int cantidadRegistrosEmpleadosPorEstado(int cantidadRegistros, bool estado, int idRol);
    int leerRegistrosEmpleadosActivos(int cantidadRegistros, int vectEmpleados[], int tam, int idRol);


private:
    std::string _nombreArchivo;
};


