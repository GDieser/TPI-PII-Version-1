#include <iostream>
#include <cstring>

#include "UsuarioAutenticado.h"

using namespace std;


UsuarioAutenticado::UsuarioAutenticado(int idUsuario, string nombre, string apellido, int dni, Fecha fechaNacimiento, Fecha fechaIngreso, int rol, bool estaHabilitado)
    : _idUsuario(idUsuario), _dni(dni), _fechaNacimiento(fechaNacimiento), _fechaIngreso(fechaIngreso), _rol(rol), _estaHabilitado(estaHabilitado)
{
    strncpy(_nombre, nombre.c_str(), sizeof(_nombre) - 1);
    _nombre[sizeof(_nombre) - 1] = '\0';

    strncpy(_apellido, apellido.c_str(), sizeof(_apellido) - 1);
    _apellido[sizeof(_apellido) - 1] = '\0';
}

UsuarioAutenticado::UsuarioAutenticado()
    : _idUsuario(0), _dni(0), _fechaNacimiento(), _fechaIngreso(), _rol(5), _estaHabilitado(false)
{
    _nombre[0] = '\0';
    _apellido[0] = '\0';
}

void UsuarioAutenticado::setEstadoHabilitado(bool estado)
{
    _estaHabilitado = estado;
}

int UsuarioAutenticado::getIdUsuario() const
{
    return _idUsuario;
}

const char* UsuarioAutenticado::getNombre() const
{
    return _nombre;
}

const char* UsuarioAutenticado::getApellido() const
{
    return _apellido;
}

int UsuarioAutenticado::getDni() const
{
    return _dni;
}

Fecha UsuarioAutenticado::getFechaNacimiento() const
{
    return _fechaNacimiento;
}

Fecha UsuarioAutenticado::getFechaIngreso() const
{
    return _fechaIngreso;
}

int UsuarioAutenticado::getRol() const
{
    return _rol;
}

bool UsuarioAutenticado::estaHabilitado() const
{
    return _estaHabilitado;
}
