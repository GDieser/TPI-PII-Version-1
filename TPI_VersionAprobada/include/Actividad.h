#pragma once


class Actividad
{
public:
    Actividad();

    Actividad(int idActividad, std::string nombre);

    int getIdActividad();
    std::string getNombre();

    void setIdActividad(int idActividad);
    void setNombre(std::string nombre);

private:

    int _idActividad;
    char _nombre[50];
};
