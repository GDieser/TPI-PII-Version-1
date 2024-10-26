#include <iostream>

#include "GestionArchivoActividades.h"

using namespace std;

GestionArchivoActividades::GestionArchivoActividades()
{

}

GestionArchivoActividades::GestionArchivoActividades(string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

bool GestionArchivoActividades::guardarActividad(Actividad actividad)
{
    bool guardo;
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "ab");

    if(pArchivo == nullptr)
    {
        return false;
    }

    guardo = fwrite(&actividad, sizeof(Actividad), 1, pArchivo);

    fclose(pArchivo);

    return guardo;
}

bool GestionArchivoActividades::guardarActividad(Actividad actividad, int posicion)
{
    bool guardo;
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(pArchivo == nullptr)
    {
        return false;
    }

    fseek(pArchivo, sizeof(Actividad) * posicion, SEEK_SET);

    guardo = fwrite(&actividad, sizeof(Actividad), 1, pArchivo);

    fclose(pArchivo);

    return guardo;
}

int GestionArchivoActividades::buscarActividad(int idActividad)
{
    int posicion = 0;
    Actividad actividad;
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(pArchivo == nullptr)
    {
        return false;
    }

    while(fread(&actividad, sizeof(Actividad), 1, pArchivo))
    {
        if(actividad.getIdActividad() == idActividad)
        {
            fclose(pArchivo);
            return posicion;
        }
        posicion++;
    }

    fclose(pArchivo);

    return -1;
}

Actividad GestionArchivoActividades::leerRegistroActividad(int posicion)
{
    Actividad actividad;
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return Actividad();
    }

    fseek(pArchivo, sizeof(Actividad) * posicion, SEEK_SET);

    fread(&actividad, sizeof(Actividad), 1, pArchivo);

    fclose(pArchivo);

    return actividad;
}

int GestionArchivoActividades::cantidadRegistrosActividades()
{
    int cantidad;

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return -1;
    }

    fseek(pArchivo, 0, SEEK_END);

    cantidad = ftell(pArchivo) / sizeof(Actividad);

    fclose(pArchivo);

    return cantidad;
}

void GestionArchivoActividades::leerRegistrosActividades(int cantidadRegistros, Actividad *vecActividad)
{
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return;
    }

    for(int i = 0; i < cantidadRegistros; i++)
    {
        fread(&vecActividad[i], sizeof(Actividad), 1, pArchivo);
    }

    fclose(pArchivo);
}

