#include <iostream>
#include <cstring>

#include "ServicioSocio.h"
#include "Socio.h"
#include "Fecha.h"

#include "ServicioEmpleado.h"
#include "ServicioPago.h"

using namespace std;


ServicioSocio::ServicioSocio()
{
    _archivoSocio = GestionArchivoSocios("archivoSocios.dat");
}

void ServicioSocio::verSocios()
{
    system("cls");


    system("pause");
}
void ServicioSocio::agregarSocio()
{

    system("pause");
}

void ServicioSocio::modificarSocio()
{

}
void ServicioSocio::verEntrenadorAsignado(int idSocio)
{
    system("cls");

    system("pause");
}

void ServicioSocio::verHorarios()
{

}

void ServicioSocio::verMembresia(int idSocio)
{
    system("cls");


    system("pause");
}

void ServicioSocio::modificarContrasenia(int idSocio)
{
    system("cls");

}

bool ServicioSocio::buscarSocioLogin(int idSocio, string pass)
{
    Socio socio;

    int cantidad = _archivoSocio.cantidadRegistrosSocios();

    for(int i=0; i < cantidad; i++)
    {
        socio = _archivoSocio.leerRegistroSocio(i);

        if(idSocio == socio.getIdUsuario() && !strcmp(socio.getContrasenia().c_str(), pass.c_str()))
        {
            return true;
        }
    }

    return false;
}

bool ServicioSocio::validarLoginAsistenciaSocio(int idSocio, int pin)
{
    system("cls");
    Socio socio;


    int cantidad = _archivoSocio.cantidadRegistrosSocios();

    for(int i=0; i<cantidad; i++)
    {
        socio = _archivoSocio.leerRegistroSocio(i);

        if(socio.getIdUsuario() == idSocio && socio.getPinIngreso() == pin)
        {
            return true;
        }
    }

    return false;

    system("pause");
}


