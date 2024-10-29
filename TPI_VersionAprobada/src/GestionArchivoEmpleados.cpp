#include <iostream>

#include "GestionArchivoEmpleados.h"

using namespace std;

GestionArchivoEmpleados::GestionArchivoEmpleados()
{

}

GestionArchivoEmpleados::GestionArchivoEmpleados(string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

bool GestionArchivoEmpleados::guardarEmpleado(Empleado empleado)
{

    bool guardo;
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "ab");

    if(pArchivo == nullptr)
    {
        return false;
    }

    guardo = fwrite(&empleado, sizeof(Empleado), 1, pArchivo);

    fclose(pArchivo);

    return guardo;

}

bool GestionArchivoEmpleados::guardarEmpleado(Empleado empleado, int posicion)
{

    bool guardo;
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(pArchivo == nullptr)
    {
        return false;
    }

    fseek(pArchivo, sizeof(Empleado) * posicion, SEEK_SET);

    guardo = fwrite(&empleado, sizeof(Empleado), 1, pArchivo);

    fclose(pArchivo);

    return guardo;

}

int GestionArchivoEmpleados::buscarEmpleado(int idEmpleado)
{
    int posicion = 0;

    Empleado empleado;

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(pArchivo == nullptr)
    {
        return false;
    }


    while(fread(&empleado, sizeof(Empleado), 1, pArchivo))
    {
        if(empleado.getIdUsuario() == idEmpleado)
        {
            fclose(pArchivo);
            return posicion;
        }
        posicion++;
    }

    fclose(pArchivo);

    return -1;

}

Empleado GestionArchivoEmpleados::leerRegistroEmpleado(int posicion)
{
    Empleado empleado;

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return Empleado();
    }

    fseek(pArchivo, sizeof(Empleado) * posicion, SEEK_SET);

    fread(&empleado, sizeof(Empleado), 1, pArchivo);

    fclose(pArchivo);

    return empleado;

}

int GestionArchivoEmpleados::cantidadRegistrosEmpleados()
{
    int cantidad;

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return -1;
    }

    fseek(pArchivo, 0, SEEK_END);

    cantidad = ftell(pArchivo) / sizeof(Empleado);

    fclose(pArchivo);

    return cantidad;

}

void GestionArchivoEmpleados::leerRegistrosEmpleados(int cantidadRegistros, Empleado *vectEmpleado)
{
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return;
    }

    for(int i = 0; i < cantidadRegistros; i++)
    {
        fread(&vectEmpleado[i], sizeof(Empleado), 1, pArchivo);
    }

    fclose(pArchivo);

}

int GestionArchivoEmpleados::cantidadRegistrosEmpleadosPorEstado(int cantidadRegistros, bool estado, int idRol)
{
    int contador  = 0;
    Empleado empleado;

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return -1;
    }

    for(int i = 0; i < cantidadRegistros; i++)
    {
        fread(&empleado, sizeof(Empleado), 1, pArchivo);
        if(empleado.getIdRol() == idRol && empleado.getEstado() == estado)
        {
            contador++;
        }
    }

    fclose(pArchivo);

    return contador;
}

int GestionArchivoEmpleados::leerRegistrosEmpleadosActivos(int cantidadRegistros, int vectEmpleados[], int tam, int idRol)
{
    int cont = 0, indice = 0;
    FILE *pArchivo;

    Empleado empleado;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return -1;
    }

    for(int i=0; i<cantidadRegistros; i++)
    {
        fread(&empleado, sizeof(Empleado), 1, pArchivo);
        if(empleado.getIdRol() == idRol && empleado.getEstado())
        {
            vectEmpleados[indice] = i;
            indice++;
        }
    }

    fclose(pArchivo);

    return *vectEmpleados;
}

