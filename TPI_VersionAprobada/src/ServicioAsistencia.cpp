#include <iostream>

#include "ServicioAsistencia.h"
#include "Fecha.h"
#include "RegistroAsistencia.h"

using namespace std;


ServicioAsistencia::ServicioAsistencia()
{
    _archivoAsitencia = GestionArchivoAsistencias("archivoAsistencias.dat");
}

void ServicioAsistencia::registrarAsistencia(int idSocio)
{
    system("cls");


}

bool ServicioAsistencia::validarRegistroDeAsistencia(int idSocio, Fecha fechaActual)
{
    system("cls");


    system("pause");
}

void ServicioAsistencia::verAsistenciaPorSocio(int idSocio)
{
    system("cls");

    system("pause");
}
