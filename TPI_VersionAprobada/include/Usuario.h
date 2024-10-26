#pragma once

#include "Fecha.h"


class Usuario
{
public:
    Usuario();
    Usuario(std::string nombre, std::string apellido, int dni, int idUsuario, Fecha fechaNacimiento, Fecha fechaIngreso, std::string contrasenia, bool estado, int idRol);

    int getIdUsuario() const;
    int getDni() const;
    int getIdRol();
    std::string getNombre() const;
    std::string getApellido() const;
    std::string getContrasenia() const;
    Fecha getFechaDeIngreso();
    Fecha getFechaNacimiento();
    bool getEstado() const;

    void setIdUsuario(int idUsuario);
    void setDni(int dni);
    void setNombre(std::string nombre);
    void setApellido(std::string apellido);
    void setContrasenia(std::string contrasenia);
    void setFechaNacimiento(Fecha fechaNacimiento);
    void setFechaDeIngreso(Fecha fechaIngreso);
    void setIdRol(int idRol);
    void setEstado(bool estadoHabilitado);


protected:

    int _idUsuario;
    int _dni;
    int _idRol;
    char _nombre[50];
    char _apellido[50];
    char _contrasenia[50];
    Fecha _fechaDeIngreso;
    Fecha _fechaNacimiento;
    bool _estadoHabilitado;
};


