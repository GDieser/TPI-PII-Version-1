#include <iostream>

#include "Empleado.h"

using namespace std;


Empleado::Empleado()
{
    //ctor
}

Empleado::Empleado(string nombre, string apellido, int dni, int idUsuario, Fecha fechaNacimiento, Fecha fechaIngreso, string contrasenia, bool estado,
                   int idRol, int legajo, int idTurno, int idActividadPrincipal)
    : Usuario(nombre, apellido, dni, idUsuario, fechaNacimiento, fechaIngreso, contrasenia, estado, idRol)
{
    setLegajo(legajo);
    setIdTurno(idTurno);
    setIdActividadPrincipal(idActividadPrincipal);
}

int Empleado::getLegajo()
{
    return _legajo;
}
int Empleado::getIdTurno()
{
    return _idTurno;
}
int Empleado::getIdActividadPrincipal()
{
    return _idActividadPrincipal;
}

void Empleado::setLegajo(int legajo)
{
    _legajo = legajo;
}
void Empleado::setIdTurno(int idTurno)
{
    _idTurno = idTurno;
}
void Empleado::setIdActividadPrincipal(int idActividadPrincipal)
{
    _idActividadPrincipal = idActividadPrincipal;
}
