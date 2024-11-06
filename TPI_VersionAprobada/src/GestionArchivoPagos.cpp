#include <iostream>

#include "GestionArchivoPagos.h"

using namespace std;

GestionArchivoPagos::GestionArchivoPagos()
{}

GestionArchivoPagos::GestionArchivoPagos(std::string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

bool GestionArchivoPagos::guardarPago(const RegistroPago& pago)
{

    FILE* pfile;
    pfile = fopen(_nombreArchivo.c_str(), "ab");
    if (pfile == nullptr)
    {
        return false;
    }

    bool result = fwrite(&pago, sizeof(RegistroPago), 1, pfile) == 1;

    fclose(pfile);

    return result;
}

bool GestionArchivoPagos::modificarPago(RegistroPago &pago, int pos)
{

    FILE* pfile;
    bool result;

    pfile = fopen(_nombreArchivo.c_str(), "rb+");
    if (pfile == nullptr)
    {
        return false;
    }

    fseek(pfile, sizeof(RegistroPago) * pos, SEEK_SET);///falta sizeof

    result = fwrite(&pago, sizeof(RegistroPago), 1, pfile) == 1;

    fclose(pfile);
    return result;
}

RegistroPago GestionArchivoPagos::leerPago(int pos)
{

    RegistroPago rp;
    FILE* pfile;
    pfile = fopen(_nombreArchivo.c_str(), "rb");
    if (pfile == nullptr)
    {
        return rp;
    }

    fseek(pfile, sizeof(RegistroPago) * pos, SEEK_SET);

    fread(&rp, sizeof(RegistroPago), 1, pfile);

    fclose(pfile);

    return rp;
}

int GestionArchivoPagos::getCantidadPagos()
{

    int totalBytes, cantReg;
    RegistroPago rp;
    FILE* pfile;
    pfile = fopen(_nombreArchivo.c_str(), "rb");
    if (pfile == nullptr)
    {
        return 0;
    }

    fseek(pfile, 0, SEEK_END);

    totalBytes = ftell(pfile);

    fclose(pfile);

    return cantReg = totalBytes / sizeof(RegistroPago);
}

void GestionArchivoPagos::leerTodosPagos(RegistroPago *vPagos, int cantPagos)
{

    FILE* pfile;
    pfile = fopen(_nombreArchivo.c_str(), "rb");

    if (pfile == nullptr)
    {
        return;
    }

    for (int i = 0; i < cantPagos; i++)
    {
        fread(&vPagos[i], sizeof(RegistroPago), cantPagos, pfile);
    }

    fclose(pfile);
}


///filtros
int GestionArchivoPagos::buscarPago(int id)
{

    RegistroPago pago;
    int pos = 0;

    FILE* pfile;
    pfile = fopen(_nombreArchivo.c_str(), "rb");
    if (pfile == nullptr)
    {
        return 0;
    }

    while (fread(&pago, sizeof(RegistroPago), 1, pfile) == 1)
    {
        if (pago.getIdUsuario() == id)
        {
            break;
        }
        pos++;
    }

    fclose(pfile);

    if (pago.getIdUsuario() == id)   // dos posibilidades, o que haya llegado al final porque lo encontro e hizo el break o porque trato de leer y no pudo
    {
        return pos;
    }
    else   // no lo encontro
    {
        return -1;
    }
}

int GestionArchivoPagos::cantidadPagosXSocio(int cantPagos, int idUsuario)
{

    RegistroPago pago;
    int cont = 0;

    FILE* pfile;
    pfile = fopen(_nombreArchivo.c_str(), "rb");

    if (pfile == nullptr)
    {
        return -1;
    }

    for (int i = 0; i < cantPagos; i++)
    {
        fread(&pago, sizeof(RegistroPago), 1, pfile);
        if (pago.getIdUsuario() == idUsuario)
        {
            cont++;
        }
    }

    fclose(pfile);
    return cont;
}

int GestionArchivoPagos::leerPagosXSocio(int cantPagos, int vPagos[], int tam, int idUsuario)
{

    RegistroPago pago;
    int index = 0;

    FILE* pfile;
    pfile = fopen(_nombreArchivo.c_str(), "rb");

    if (pfile == nullptr)
    {
        return -1;
    }

    for (int i = 0; i < cantPagos; i++)
    {
        fread(&pago, sizeof(RegistroPago), 1, pfile);
        if (pago.getIdUsuario() == idUsuario)
        {
            vPagos[index] = i;
            index++;
        }
    }

    fclose(pfile);
    return *vPagos;
}

int GestionArchivoPagos::ultimoPagoSocio(int cantPagos, int idUsuario)
{

    RegistroPago pago;

    int pos = -1;
    FILE *pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if (pArchivo == nullptr)
    {
        return -1;
    }

    for(int i = 0; i < cantPagos; i++)
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
