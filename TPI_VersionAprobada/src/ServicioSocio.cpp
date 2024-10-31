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

int ServicioSocio::obternerUltimoIdSocio()
{
    Socio socio;

    int cantidad = _archivoSocio.cantidadRegistrosSocios();

    if(cantidad > 0)
    {
        socio = _archivoSocio.leerRegistroSocio(cantidad - 1);
        return socio.getIdUsuario();
    }

    return -1;
}

void ServicioSocio::mostrarSociosPorEntrenador(int idEntrenador)
{
    Socio socio;

    int cantidad = _archivoSocio.cantidadRegistrosSocios();

    for(int i=0; i<cantidad; i++)
    {
        socio = _archivoSocio.leerRegistroSocio(i);
        if(socio.getIdEntrenadorAsignado() == idEntrenador)
        {
            cout << socio.getNombre() << " " << socio.getApellido() << " ID: #" << socio.getIdUsuario() << endl;
        }
    }
}


