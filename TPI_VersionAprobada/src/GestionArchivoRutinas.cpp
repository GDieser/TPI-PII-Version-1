#include <iostream>

#include "GestionArchivoRutinas.h"

using namespace std;

GestionArchivoRutinas::GestionArchivoRutinas()
{

}

GestionArchivoRutinas::GestionArchivoRutinas(string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

bool GestionArchivoRutinas::guardarRutina(Rutina rutina)
{
    bool guardo;
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "ab");

    if(pArchivo == nullptr)
    {
        return false;
    }

    guardo = fwrite(&rutina, sizeof(Rutina), 1, pArchivo);

    fclose(pArchivo);

    return guardo;
}

bool GestionArchivoRutinas::guardarRutina(Rutina rutina, int posicion)
{
    bool guardo;
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(pArchivo == nullptr)
    {
        return false;
    }

    fseek(pArchivo, sizeof(Rutina) * posicion, SEEK_SET);

    guardo = fwrite(&rutina, sizeof(Rutina), 1, pArchivo);

    fclose(pArchivo);

    return guardo;
}

int GestionArchivoRutinas::buscarRutina(int idRutina)
{
    int posicion = 0;
    Rutina rutina;

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(pArchivo == nullptr)
    {
        return -1;
    }

    while(fread(&rutina, sizeof(Rutina), 1, pArchivo))
    {
        if(rutina.getIdRutina() == idRutina)
        {
            fclose(pArchivo);
            return posicion;
        }
        posicion++;
    }

    fclose(pArchivo);

    return -1;
}

Rutina GestionArchivoRutinas::leerRegistroRutina(int posicion)
{
    Rutina rutina;

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return Rutina();
    }

    fseek(pArchivo, sizeof(Rutina) * posicion, SEEK_SET);

    fread(&rutina, sizeof(Rutina), 1, pArchivo);

    fclose(pArchivo);

    return rutina;
}

int GestionArchivoRutinas::cantidadRegistrosRutinas()
{
    int cantidad;

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return -1;
    }

    fseek(pArchivo, 0, SEEK_END);

    cantidad = ftell(pArchivo) / sizeof(Rutina);

    fclose(pArchivo);

    return cantidad;
}

void GestionArchivoRutinas::leerRegistrosRutina(int cantidadRegistros, Rutina *vecRutina)
{
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return;
    }

    for(int i = 0; i < cantidadRegistros; i++)
    {
        fread(&vecRutina[i], sizeof(Rutina), 1, pArchivo);
    }

    fclose(pArchivo);
}

int GestionArchivoRutinas::cantidadDeRegistrosPorEntrenador(int cantidadRegistros, int idEntrenador)
{
    int cont = 0;
    FILE *pArchivo;

    Rutina rutina;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return -1;
    }

    for(int i=0; i<cantidadRegistros; i++)
    {
        fread(&rutina, sizeof(Rutina), 1, pArchivo);
        if(rutina.getIdEntrenador() == idEntrenador)
        {
            cont++;
        }
    }

    fclose(pArchivo);

    return cont;

}

int GestionArchivoRutinas::leerRegistrosRutinasPorEntrenador(int cantidadRegistros, int vectRutina[], int tam, int idEntrenador)
{
    int cont = 0, indice = 0;
    FILE *pArchivo;

    Rutina rutina;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return -1;
    }

    for(int i=0; i<cantidadRegistros; i++)
    {
        fread(&rutina, sizeof(Rutina), 1, pArchivo);
        if(rutina.getIdEntrenador() == idEntrenador)
        {
            vectRutina[indice] = i;
            indice++;
        }
    }

    fclose(pArchivo);

    return *vectRutina;
}


