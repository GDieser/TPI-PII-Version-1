#include <iostream>
#include <cstring>

#include "ServicioEmpleado.h"
#include "ServicioSocio.h"
#include "ServicioActividad.h"

using namespace std;


ServicioEmpleado::ServicioEmpleado()
{
    _archivoEmpleado = GestionArchivoEmpleados("archivoEmpleados.dat");
}

void ServicioEmpleado::verEntrenadores()
{
    system("cls");


    system("pause");
}

void ServicioEmpleado::verGerentes()
{


    system("pause");
}

void ServicioEmpleado::agregarGerenete()
{


}

void ServicioEmpleado::agregarEntrenador()
{


    system("pause");


}
void ServicioEmpleado::modificarEmpleado()
{

}

void ServicioEmpleado::verSociosAsignados()
{

}

void ServicioEmpleado::asignarHorarios()
{

}

void ServicioEmpleado::verHorariosAsignados()
{

}

bool ServicioEmpleado::buscarEmpleadoLogin(int idEmpleado, string pass)
{
    Empleado empleado;

    int cantidad = _archivoEmpleado.cantidadRegistrosEmpleados();

    for(int i=0; i < cantidad; i++)
    {
        empleado = _archivoEmpleado.leerRegistroEmpleado(i);

        if(idEmpleado == empleado.getIdUsuario() && !strcmp(empleado.getContrasenia().c_str(), pass.c_str()))
        {
            return true;
        }
    }

    return false;
}

void ServicioEmpleado::modificarContrasenia(int idEmpleado)
{
    system("cls");

}

