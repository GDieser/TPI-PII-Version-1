#include <iostream>

#include "GestionArchivoPagos.h"

using namespace std;

GestionArchivoPagos::GestionArchivoPagos()
{

}

GestionArchivoPagos::GestionArchivoPagos(string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

bool GestionArchivoPagos::guardarPago(RegistroPago pago)
{
    bool guardo;
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "ab");

    if(pArchivo == nullptr)
    {
        return false;
    }

    guardo = fwrite(&pago, sizeof(RegistroPago), 1, pArchivo);

    fclose(pArchivo);

    return guardo;

}

bool GestionArchivoPagos::guardarPago(RegistroPago pago, int posicion)
{
    bool guardo;
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(pArchivo == nullptr)
    {
        return false;
    }

    fseek(pArchivo, sizeof(RegistroPago) * posicion, SEEK_SET);

    guardo = fwrite(&pago, sizeof(RegistroPago), 1, pArchivo);

    fclose(pArchivo);

    return guardo;

}

int GestionArchivoPagos::buscarPago(int idUsuario)
{
    int posicion = 0;

    RegistroPago pago;

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(pArchivo == nullptr)
    {
        return false;
    }


    while(fread(&pago, sizeof(RegistroPago), 1, pArchivo))
    {
        if(pago.getIdUsuario() == idUsuario)
        {
            fclose(pArchivo);
            return posicion;
        }
        posicion++;
    }

    fclose(pArchivo);

    return -1;

}

RegistroPago GestionArchivoPagos::leerRegistroPago(int posicion)
{
    RegistroPago pago;

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return RegistroPago();
    }

    fseek(pArchivo, sizeof(RegistroPago) * posicion, SEEK_SET);

    fread(&pago, sizeof(RegistroPago), 1, pArchivo);

    fclose(pArchivo);

    return pago;

}

int GestionArchivoPagos::cantidadRegistrosPagos()
{
    int cantidad;

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return -1;
    }

    fseek(pArchivo, 0, SEEK_END);

    cantidad = ftell(pArchivo)/ sizeof(RegistroPago);

    fclose(pArchivo);

    return cantidad;

}

void GestionArchivoPagos::leerRegistrosPagos(int cantidadRegistros, RegistroPago *vectPago)
{
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return;
    }

    for(int i=0; i < cantidadRegistros; i++)
    {
        fread(&vectPago[i], sizeof(RegistroPago), 1, pArchivo);
    }

    fclose(pArchivo);

}

int GestionArchivoPagos::cantidadDeRegistrosSocios(int cantidadRegistros, int idUsuario)
{
    int cont = 0;
    FILE *pArchivo;

    RegistroPago pago;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return -1;
    }

    for(int i=0; i<cantidadRegistros; i++)
    {
        fread(&pago, sizeof(RegistroPago), 1, pArchivo);
        if(pago.getIdUsuario() == idUsuario)
        {
            cont++;
        }
    }

    fclose(pArchivo);

    return cont;

}

int GestionArchivoPagos::leerRegistrosPagosSocios(int cantidadRegistros, int vectPagos[], int tam, int idUsuario)
{
    int cont = 0, indice = 0;
    FILE *pArchivo;

    RegistroPago pago;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return -1;
    }

    for(int i=0; i<cantidadRegistros; i++)
    {
        fread(&pago, sizeof(RegistroPago), 1, pArchivo);
        if(pago.getIdUsuario() == idUsuario)
        {
            vectPagos[indice] = i;
            indice++;
        }
    }

    fclose(pArchivo);

    return *vectPagos;
}

int GestionArchivoPagos::ultimoRegistroSocio(int cantidadRegistros, int idUsuario)
{
    int pos = -1;
    FILE *pArchivo;

    RegistroPago pago;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return -1;
    }

    for(int i=0; i<cantidadRegistros; i++)
    {
        fread(&pago, sizeof(RegistroPago), 1, pArchivo);
        if(pago.getIdUsuario() == idUsuario)
        {
            pos = i;
        }
    }

    fclose(pArchivo);

    return pos;
}
