#include <iostream>

#include "RegistroAsistencia.h"

using namespace std;

RegistroAsistencia::RegistroAsistencia()
{
    //ctor
}

RegistroAsistencia::RegistroAsistencia(int idSocio, Fecha fecha)
{
    setIdSocio(idSocio);
    setFecha(fecha);
}

int RegistroAsistencia::getIdSocio()
{
    return _idSocio;
}

Fecha RegistroAsistencia::getFecha()
{
    return _fecha;
}

void RegistroAsistencia::setIdSocio(int idSocio)
{
    _idSocio = idSocio;
}

void RegistroAsistencia::setFecha(Fecha fecha)
{
    _fecha = fecha;
}

