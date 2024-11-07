#include <iostream>
#include <cstring>

#include "Usuario.h"

using namespace std;

Usuario::Usuario()
{

}

Usuario::Usuario(string nombre, string apellido, int dni, int idUsuario, Fecha fechaNacimiento, Fecha fechaIngreso, string contrasenia, bool estado, int idRol)
{
    setNombre(nombre);
    setApellido(apellido);
    setDni(dni);
    setIdUsuario(idUsuario);
    setFechaNacimiento(fechaNacimiento);
    setFechaDeIngreso(fechaIngreso);
    setIdRol(idRol);
    setContrasenia(contrasenia);
    setEstado(estado);
}

int Usuario::getIdUsuario() const
{
    return _idUsuario;
}
int Usuario::getDni() const
{
    return _dni;
}
string Usuario::getNombre() const
{
    return _nombre;
}
string Usuario::getApellido() const
{
    return _apellido;
}
string Usuario::getContrasenia() const
{
    return _contrasenia;
}
Fecha Usuario::getFechaDeIngreso()
{
    return _fechaDeIngreso;
}
Fecha Usuario::getFechaNacimiento()
{
    return _fechaNacimiento;
}
int Usuario::getIdRol()
{
    return _idRol;
}
bool Usuario::getEstado() const
{
    return _estadoHabilitado;
}

void Usuario::setIdUsuario(int idUsuario)
{
    _idUsuario = idUsuario;
}
void Usuario::setDni(int dni)
{
    _dni = dni;
}
void Usuario::setNombre(string nombre)
{
    strcpy(_nombre, nombre.c_str());
}
void Usuario::setApellido(string apellido)
{
    strcpy(_apellido, apellido.c_str());
}
void Usuario::setContrasenia(string contrasenia)
{
    strcpy(_contrasenia, contrasenia.c_str());
}
void Usuario::setFechaNacimiento(Fecha fechaNacimiento)
{
    _fechaNacimiento = fechaNacimiento;
}
void Usuario::setFechaDeIngreso(Fecha fechaIngreso)
{
    _fechaDeIngreso = fechaIngreso;
}
void Usuario::setIdRol(int idRol)
{
    _idRol = idRol;
}
void Usuario::setEstado(bool estadoHabilitado)
{
    _estadoHabilitado = estadoHabilitado;
}
