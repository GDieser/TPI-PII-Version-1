#pragma once

#include "Fecha.h"


class RegistroAsistencia
{
public:
    RegistroAsistencia();

    RegistroAsistencia(int idSocio, Fecha fecha);

    int getIdSocio();
    Fecha getFecha();

    //int getIdActividad();

    void setIdSocio(int idSocio);
    void setFecha(Fecha fecha);

    //void setIdActividad(int idActividad);

private:

    int _idSocio;
    Fecha _fecha;

    //int _idActividad;
};
