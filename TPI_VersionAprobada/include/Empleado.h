#pragma once

#include "Usuario.h"



class Empleado : public Usuario
{
public:
    Empleado();
    Empleado(std::string nombre, std::string apellido, int dni, int idUsuario, Fecha fechaNacimiento, Fecha fechaIngreso, std::string contrasenia,
          bool estado, int idRol, int legajo, int idTurno, int idActividadPrincipal);

    int getLegajo();
    int getIdTurno();
    int getIdActividadPrincipal();

    void setLegajo(int legajo);
    void setIdTurno(int idTurno);
    void setIdActividadPrincipal(int idActividadPrincipal);

protected:
    int _legajo;
    int _idTurno;
    int _idActividadPrincipal;
};
