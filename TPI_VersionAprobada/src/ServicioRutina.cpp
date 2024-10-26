#include <iostream>

#include "ServicioRutina.h"
#include "Rutina.h"

using namespace std;


ServicioRutina::ServicioRutina()
{
    _archivoRutina = GestionArchivoRutinas("archivoRutinas.dat");
    _archivoDetallesRutina = GestionArchivoDetalleRutinas("archivoDetalleRutinas.dat");
}

void ServicioRutina::verRutinas(int idEntrenador)
{
    system("cls");


    system("pause");
}

void ServicioRutina::verDetallesDeRutina()
{
    system("cls");

}

void ServicioRutina::crearRutina(int idEntrenador)
{

}

DetalleRutina ServicioRutina::crearDetalleRutina(int idRutina)
{

}

void ServicioRutina::modificarRutina(int idEntrenador)
{
    system("cls");



    system("pause");
}
void ServicioRutina::asignarRutina()
{
    system("cls");


    system("pause");
}

int ServicioRutina::obtenerUltimoIdRutina() ///Que arranque en 1 y sea autonumerico
{


}
