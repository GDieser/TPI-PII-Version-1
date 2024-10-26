#include <iostream>

#include "ServicioReclamo.h"
#include "Reclamo.h"
#include "Fecha.h"

using namespace std;


ServicioReclamo::ServicioReclamo()
{
    _archivoReclamos = GestionArchivoReclamos("archivoReclamos.dat");
}

void ServicioReclamo::verReclamos(bool resuelto)
{
    system("cls");

    system("pause");
}

void ServicioReclamo::verReclamoUsusario(int idUsuario)
{
    system("cls");


    system("pause");
}
void ServicioReclamo::iniciarReclamo(int idUsuario)
{
    system("cls");


    system("pause");
}

void ServicioReclamo::cambiarEstadoReclamo()
{
    system("cls");

    system("pause");
}

///Para autonumerar los IdReclamos, podria empezar en #1
int ServicioReclamo::obtenerUltimoIdReclamo()
{


}
