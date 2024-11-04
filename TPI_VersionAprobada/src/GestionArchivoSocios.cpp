#include <iostream>

#include "GestionArchivoSocios.h"

using namespace std;

GestionArchivoSocios::GestionArchivoSocios()
{

}

GestionArchivoSocios::GestionArchivoSocios(string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

bool GestionArchivoSocios::guardarSocio(Socio socio)
{
    bool guardo;
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "ab");

    if(pArchivo == nullptr)
    {
        return false;
    }

    guardo = fwrite(&socio, sizeof(Socio), 1, pArchivo);

    fclose(pArchivo);

    return guardo;
}

bool GestionArchivoSocios::guardarSocio(Socio socio, int posicion)
{
    bool guardo;
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(pArchivo == nullptr)
    {
        return false;
    }

    fseek(pArchivo, sizeof(Socio) * posicion, SEEK_SET);

    guardo = fwrite(&socio, sizeof(Socio), 1, pArchivo);

    fclose(pArchivo);

    return guardo;
}

int GestionArchivoSocios::buscarSocio(int idSocio)
{
    int posicion = 0;

    Socio socio;

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return false;
    }


    while(fread(&socio, sizeof(Socio), 1, pArchivo))
    {
        if(socio.getIdUsuario() == idSocio)
        {
            fclose(pArchivo);
            return posicion;
        }
        posicion++;
    }

    fclose(pArchivo);

    return -1;
}

Socio GestionArchivoSocios::leerRegistroSocio(int posicion)
{
    Socio socio;

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return Socio();
    }

    fseek(pArchivo, sizeof(Socio) * posicion, SEEK_SET);

    fread(&socio, sizeof(Socio), 1, pArchivo);

    fclose(pArchivo);

    return socio;
}

int GestionArchivoSocios::cantidadRegistrosSocios()
{
    int cantidad;

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return -1;
    }

    fseek(pArchivo, 0, SEEK_END);

    cantidad = ftell(pArchivo)/ sizeof(Socio);

    fclose(pArchivo);

    return cantidad;
}

void GestionArchivoSocios::leerRegistrosSocios(int cantidadRegistros, Socio *vecSocio)
{
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return;
    }

    for(int i=0; i < cantidadRegistros; i++)
    {
        fread(&vecSocio[i], sizeof(Socio), 1, pArchivo);
    }

    fclose(pArchivo);
}
