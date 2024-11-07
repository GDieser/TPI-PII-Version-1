#include <iostream>
#include <cstring>

#include "Actividad.h"


using namespace std;

Actividad::Actividad()
{

}

Actividad::Actividad(int idActividad, string nombre)
{
    setIdActividad(idActividad);
    setNombre(nombre);
}

int Actividad::getIdActividad()
{
    return _idActividad;
}
string Actividad::getNombre()
{
    return _nombre;
}

void Actividad::setIdActividad(int idActividad)
{
    _idActividad = idActividad;
}
void Actividad::setNombre(string nombre)
{
    strcpy(_nombre, nombre.c_str());
}
