#include <iostream>
#include <cstring>
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
    Fecha hoy = Fecha();
    if(validarRegistroDeAsistencia(idSocio, hoy)){
        RegistroAsistencia reg = RegistroAsistencia(idSocio, hoy);
        _archivoAsitencia.guardarAsistencia(reg);
        cout << "Asistencia registrada correctamente!"<< endl;
    } else {
        cout << "Usted ya registro su asistencia para el dia de la fecha" << endl;
    }
    system("pause");
    system("cls");
}

bool ServicioAsistencia::validarRegistroDeAsistencia(int idSocio, Fecha fechaActual)
{
    system("cls");
    RegistroAsistencia reg;
    int cant = _archivoAsitencia.cantidadRegistrosAsistencias();
    for(int i =0; i< cant; i++){
        reg = _archivoAsitencia.leerRegistroAsistencia(i);
        if(fechaActual.compararSiFechasSonIguales(reg.getFecha()) && idSocio == reg.getIdSocio()){
            return false;
        }
    }
    return true;
}

void ServicioAsistencia::verAsistenciaPorSocio(int idSocio)
{
    system("cls");
    RegistroAsistencia reg;
    int cant = _archivoAsitencia.cantidadRegistrosAsistencias();
    cout << "Fecha " << endl;
    cout << string(78, '-') << endl;
    for(int i =0; i< cant; i++){
        reg = _archivoAsitencia.leerRegistroAsistencia(i);
        if(idSocio == reg.getIdSocio()){
            cout << reg.getFecha().toString() << endl;
        }
    }
}

void ServicioAsistencia::verAsistenciaPorSocioPorMes(int idSocio, int mes)
{
    system("cls");
    RegistroAsistencia reg;
    int contadorMes = 0;

    int cant = _archivoAsitencia.cantidadRegistrosAsistencias();

    for (int i = 0; i < cant; i++)
    {
        reg = _archivoAsitencia.leerRegistroAsistencia(i);
        if(idSocio == reg.getIdSocio() && mes == reg.getFecha().getMes())
        {
            contadorMes++;
        }
    }

    cout << " Cantidad de asistencias en un mes: " << contadorMes << endl;
    system("pause");
}

void ServicioAsistencia::verAsistenciaPorSocioPorAnio(int idSocio, int anio)
{
    system("cls");
    RegistroAsistencia reg;
    int contadorAnio = 0;

    int cant = _archivoAsitencia.cantidadRegistrosAsistencias();

    for (int i = 0; i < cant; i++)
    {
        reg = _archivoAsitencia.leerRegistroAsistencia(i);
        if(idSocio == reg.getIdSocio() && anio == reg.getFecha().getAnio())
        {
            contadorAnio++;
        }
    }

    cout << " Cantidad de asistencias en un anio: " << contadorAnio << endl;
    system("pause");
}

void ServicioAsistencia::verTodasLasAsistencia(){
    system("cls");
    RegistroAsistencia reg;
    int cant = _archivoAsitencia.cantidadRegistrosAsistencias();
    cout << string(30, '-') << endl;
    cout << "| Fecha \t|Socio ID \t|" << endl;
    cout << string(30, '-') << endl;
    for(int i =0; i< cant; i++){
        reg = _archivoAsitencia.leerRegistroAsistencia(i);
        cout << reg.getFecha().toString() << "\t" << reg.getIdSocio() << " \t|"<<endl;
    }
}

void ServicioAsistencia::verAsistenciasEnPeriodo(int mes, int anio){
    system("cls");
    RegistroAsistencia reg;
    int cant = _archivoAsitencia.cantidadRegistrosAsistencias();
    cout << string(30, '-') << endl;
    cout << "| Fecha \t|Socio ID \t|" << endl;
    cout << string(30, '-') << endl;
    for(int i =0; i< cant; i++){
        reg = _archivoAsitencia.leerRegistroAsistencia(i);
        if(reg.getFecha().getMes()==mes && reg.getFecha().getAnio()==anio)
        cout << reg.getFecha().toString() << "\t" << reg.getIdSocio() << " \t|"<<endl;
    }
}

void ServicioAsistencia::verAsistenciasEnAnio(int anio){
    system("cls");
    RegistroAsistencia reg;
    int cant = _archivoAsitencia.cantidadRegistrosAsistencias();
    cout << string(30, '-') << endl;
    cout << "| Fecha \t|Socio ID \t|" << endl;
    cout << string(30, '-') << endl;
    for(int i =0; i< cant; i++){
        reg = _archivoAsitencia.leerRegistroAsistencia(i);
        if(reg.getFecha().getAnio()==anio)
        cout << reg.getFecha().toString() << "\t" << reg.getIdSocio() << " \t|"<<endl;
    }
}


