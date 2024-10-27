#pragma once

#include "Fecha.h"

class UsuarioAutenticado
{

public:

    UsuarioAutenticado(int idUsuario, std::string nombre, std::string apellido, int dni, Fecha fechaNacimiento, Fecha fechaIngreso, int rol, bool estaHabilitado);
    UsuarioAutenticado();


    int getIdUsuario() const;
    const char* getNombre() const;
    const char* getApellido() const;
    int getDni() const;
    Fecha getFechaNacimiento() const;
    Fecha getFechaIngreso() const;
    int getRol() const;
    bool estaHabilitado() const;

private:

    int _idUsuario;
    int _dni;
    int _rol;
    char _nombre[50];
    char _apellido[50];
    bool _estaHabilitado;
    Fecha _fechaNacimiento;
    Fecha _fechaIngreso;
};
