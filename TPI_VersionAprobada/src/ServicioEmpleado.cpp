#include <iostream>
#include <cstring>

#include "ServicioEmpleado.h"
#include "ServicioSocio.h"
#include "ServicioActividad.h"

using namespace std;


ServicioEmpleado::ServicioEmpleado()
{
    _archivoEmpleado = GestionArchivoEmpleados("archivoEmpleados.dat");
}

void ServicioEmpleado::verEntrenadores()
{
    system("cls");
    Empleado entrenador;

    int cantidad = _archivoEmpleado.cantidadRegistrosEmpleados();

    for(int i=0; i<cantidad; i++)
    {
        entrenador = _archivoEmpleado.leerRegistroEmpleado(i);

        if(entrenador.getIdRol() == 1 && entrenador.getEstado())
        {
            cout << "---------------------------" << endl;
            cout << " Nombre: " << entrenador.getNombre() << endl;
            cout << " Apellido: " << entrenador.getApellido() << endl;
            cout << " Fecha de ingreso: " << entrenador.getFechaDeIngreso().toString() << endl;
            cout << " Legajo: " << entrenador.getLegajo() << endl;
            ///Agregar Actividad principal
        }
    }

    system("pause");
}

void ServicioEmpleado::verGerentes()
{
    system("cls");

    Empleado gerente;

    int cantidad = _archivoEmpleado.cantidadRegistrosEmpleados();

    for(int i=0; i<cantidad; i++)
    {
        gerente = _archivoEmpleado.leerRegistroEmpleado(i);

        if(gerente.getIdRol() == 0 && gerente.getEstado())
        {
            cout << "---------------------------" << endl;
            cout << " Nombre: " << gerente.getNombre() << endl;
            cout << " Apellido: " << gerente.getApellido() << endl;
            cout << " Fecha de ingreso: " << gerente.getFechaDeIngreso().toString() << endl;
            cout << " Legajo: " << gerente.getLegajo() << endl;
        }
    }

    system("pause");
}

void ServicioEmpleado::agregarGerente()
{
    string nombre, apellido, contrasenia;
    int dni, idUsuario;
    int dia, mes, anio;
    Fecha fechaIngreso;
    bool estado = true;
    int idRol = 0, legajo, idTurno, idActividadPrincipal = 0;
    bool semana[7] = {};


    ServicioEmpleado servi;

    system("cls");

    cout << " AGREGAR NUEVO GERENTE: " << endl;
    cout << endl;
    cout << " Nombre: ";
    cin >> nombre;
    cout << " Apellido: ";
    cin >> apellido;
    cout << " DNI: ";
    cin >> dni;
    cout << " Dia de nacimiento: ";
    cin >> dia;
    cout << " Mes de nacimiento: ";
    cin >> mes;
    cout << " Anio de nacimiento: ";
    cin >> anio;
    cout << " Turno: ";
    cin >> idTurno;
    ///Deberia quedar mas sofisticado el ingreso de la contraseña
    cout << " Ingrese contrasenia: ";
    cin >> contrasenia;


    Fecha fechaNacimiento(dia, mes, anio);

    idUsuario = servi.obternerUltimoId();
    legajo = servi.obternerUltimoLegajo();

    Empleado empleado(nombre, apellido, dni, idUsuario, fechaNacimiento, fechaIngreso, contrasenia, estado, idRol, legajo, idTurno, idActividadPrincipal, semana);

    system("cls");
    if(_archivoEmpleado.guardarEmpleado(empleado))
    {

        cout << "Gerente ID# " << idUsuario << ", legajo " << legajo << " agregado exitosamente." << endl;
    }
    else
    {
        cout << "Error de ingreso" << endl;
    }

    system("pause");

}

void ServicioEmpleado::agregarEntrenador()
{
    string nombre, apellido, contrasenia;
    int dni, idUsuario, opcion;
    int dia, mes, anio;
    Fecha fechaIngreso;
    bool estado = true, semana[7] = {};
    int idRol = 1, legajo, idTurno, idActividadPrincipal;

    ServicioActividad actividad;

    ServicioEmpleado servi;

    system("cls");

    cout << " AGREGAR NUEVO ENTRENADOR: " << endl;
    cout << endl;
    cout << " Nombre: ";
    cin >> nombre;
    cout << " Apellido: ";
    cin >> apellido;
    cout << " DNI: ";
    cin >> dni;
    cout << " Dia de nacimiento: ";
    cin >> dia;
    cout << " Mes de nacimiento: ";
    cin >> mes;
    cout << " Anio de nacimiento: ";
    cin >> anio;
    cout << " Turno: ";
    cin >> idTurno;

    cout << " Ingrese contrasenia: ";
    cin >> contrasenia;

    cout << " 1- Ver Lista de Actividades | 2 - Agregar nueva Actividad " << endl;
    cin >> opcion;

    if(opcion == 1)
    {
        actividad.listarActividades();
        cout << endl;
        cout << " ID Actividad principal: ";
        cin >> idActividadPrincipal;
    }
    else
    {
        idActividadPrincipal = actividad.agregarActividad();
    }



    Fecha fechaNacimiento(dia, mes, anio);

    idUsuario = servi.obternerUltimoId();
    legajo = servi.obternerUltimoLegajo();

    Empleado empleado(nombre, apellido, dni, idUsuario, fechaNacimiento, fechaIngreso, contrasenia, estado, idRol, legajo, idTurno, idActividadPrincipal, semana);

    system("cls");
    if(_archivoEmpleado.guardarEmpleado(empleado))
    {

        cout << "Gerente ID# " << idUsuario <<  ", legajo " << legajo << " agregado exitosamente." << endl;
    }
    else
    {
        cout << "Error de ingreso" << endl;
    }

    system("pause");


}
void ServicioEmpleado::modificarEmpleado()
{

}

void ServicioEmpleado::verSociosAsignados()
{

}

void ServicioEmpleado::asignarHorarios()
{

}

void ServicioEmpleado::verHorariosAsignados()
{

}

int ServicioEmpleado::obternerUltimoIdEmpleado()
{
    Empleado empleado;

    int cantidad = _archivoEmpleado.cantidadRegistrosEmpleados();

    if(cantidad > 0)
    {
        empleado = _archivoEmpleado.leerRegistroEmpleado(cantidad - 1);
        return empleado.getIdUsuario();
    }

    return -1;
}

int ServicioEmpleado::obternerUltimoId()
{
    ServicioSocio socio;

    if(socio.obternerUltimoIdSocio() > obternerUltimoIdEmpleado())
    {
        return socio.obternerUltimoIdSocio()+1;
    }
    else
    {
        return obternerUltimoIdEmpleado()+1;
    }
}

int ServicioEmpleado::obternerUltimoLegajo()
{
    Empleado empleado;

    int cantidad = _archivoEmpleado.cantidadRegistrosEmpleados();

    if(cantidad > 0)
    {
        empleado = _archivoEmpleado.leerRegistroEmpleado(cantidad - 1);
        return empleado.getLegajo()+1;
    }

    return -1;
}


void ServicioEmpleado::modificarContrasenia(int idEmpleado)
{
    system("cls");
    string pass, pass2;
    Empleado empleado;


    int posicion = _archivoEmpleado.buscarEmpleado(idEmpleado);

    empleado = _archivoEmpleado.leerRegistroEmpleado(posicion);

    cout << " MODIFICAR CONTRASENIA" << endl;
    cout << "-----------------------------" << endl;
    cout << " Ingrese contrasenia actual: " << endl;
    cin >> pass;

    if(!strcmp(empleado.getContrasenia().c_str(), pass.c_str()))
    {
        cout << " Ingrese la nueva contrasenia: " << endl;
        cin >> pass;
        cout << " Repita la nueva contrasenia: " << endl;
        cin >> pass2;
        if(!strcmp(pass.c_str(), pass2.c_str()))
        {
            empleado.setContrasenia(pass);
            _archivoEmpleado.guardarEmpleado(empleado, posicion);
        }
        else
        {
            cout << "Las contrasenias no coinciden" << endl;
            system("pause");
            return;
        }
    }
    else
    {
        cout << "Contrasenia incorrecta" << endl;
        system("pause");
        return;
    }

}

bool ServicioEmpleado::buscarUnEmpleado(int idEmpleado)
{
    Empleado empleado;
    ServicioActividad actividad;

    int pos = _archivoEmpleado.buscarEmpleado(idEmpleado);

    if(pos != -1)
    {
        empleado = _archivoEmpleado.leerRegistroEmpleado(pos);

        cout << " Nombre: " << empleado.getNombre() << endl;
        cout << " Legajo: " << empleado.getLegajo() << endl;
        actividad.buscarActividad(empleado.getIdActividadPrincipal());

        return true;
    }
    else
    {
        return false;
    }
}
