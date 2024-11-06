#include <iostream>

#include "GestionArchivoAsistencias.h"

using namespace std;

GestionArchivoAsistencias::GestionArchivoAsistencias()
{

}

GestionArchivoAsistencias::GestionArchivoAsistencias(string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}


bool GestionArchivoAsistencias::guardarAsistencia(RegistroAsistencia asistencia)
{
    bool guardo;
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "ab");

    if(pArchivo == nullptr)
    {
        return false;
    }

    guardo = fwrite(&asistencia, sizeof(RegistroAsistencia), 1, pArchivo);

    fclose(pArchivo);

    return guardo;
}


bool GestionArchivoAsistencias::guardarAsistencia(RegistroAsistencia asistencia, int posicion)
{
    bool guardo;
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(pArchivo == nullptr)
    {
        return false;
    }

    fseek(pArchivo, sizeof(RegistroAsistencia) * posicion, SEEK_SET);

    guardo = fwrite(&asistencia, sizeof(RegistroAsistencia), 1, pArchivo);

    fclose(pArchivo);

    return guardo;
}


int GestionArchivoAsistencias::buscarAsistencia(int idSocio)
{
    int posicion = 0;
    RegistroAsistencia asistencia;

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return -1;
    }

    while(fread(&asistencia, sizeof(RegistroAsistencia), 1, pArchivo))
    {
        if(asistencia.getIdSocio() == idSocio)
        {
            fclose(pArchivo);
            return posicion;
        }
        posicion++;
    }

    fclose(pArchivo);

    return -1;
}


RegistroAsistencia GestionArchivoAsistencias::leerRegistroAsistencia(int posicion)
{
    RegistroAsistencia asistencia;

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return RegistroAsistencia();
    }

    fseek(pArchivo, sizeof(RegistroAsistencia) * posicion, SEEK_SET);

    fread(&asistencia, sizeof(RegistroAsistencia), 1, pArchivo);

    fclose(pArchivo);

    return asistencia;
}

int GestionArchivoAsistencias::cantidadRegistrosAsistencias()
{
    int cantidad;

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return -1;
    }

    fseek(pArchivo, 0, SEEK_END);

    cantidad = ftell(pArchivo) / sizeof(RegistroAsistencia);

    fclose(pArchivo);

    return cantidad;
}

void GestionArchivoAsistencias::leerRegistrosAsistencia(int cantidadRegistros, RegistroAsistencia *vecAsistencia)
{
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return;
    }

    for(int i = 0; i < cantidadRegistros; i++)
    {
        fread(&vecAsistencia[i], sizeof(RegistroAsistencia), 1, pArchivo);
    }

    fclose(pArchivo);
}
