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

    Empleado buscarEmpleadoPorIdSocio(int id);

<<<<<<< HEAD
    int cantidadRegistrosEmpleadosPorEstado(int cantidadRegistros, bool estado, int idRol);
    int leerRegistrosEmpleadosActivos(int cantidadRegistros, int vectEmpleados[], int tam, int idRol);

=======
>>>>>>> 61682c56dbefe582e24cfc300e37a2353cffb607
private:
    std::string _nombreArchivo;
};


