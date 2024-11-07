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

        cout << "+--------------------------------------+" << endl;
        cout << "| Asistencia registrada correctamente! |"<< endl;
        cout << "+--------------------------------------+" << endl;

    } else {
        cout << "+----------------------------------------------------------+" << endl;
        cout << "| Usted ya registro su asistencia para el dia de la fecha  |" << endl;
        cout << "+----------------------------------------------------------+" << endl;
    }

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


