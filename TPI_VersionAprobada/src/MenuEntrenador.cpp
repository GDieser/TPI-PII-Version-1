#include <iostream>

#include "MenuEntrenador.h"
#include "ServicioEmpleado.h"
#include "ServicioReclamo.h"
#include "ServicioEjercicio.h"
#include "ServicioRutina.h"

using namespace std;


MenuEntrenador::MenuEntrenador(UsuarioAutenticado usuario) : _usuario(usuario) {}

void MenuEntrenador::mostrarMenuEntrenador()
{
    int opcion;
    ServicioEmpleado entrenador;

    do
    {
        system("cls");
        cout << "  ENTRENADOR: #" << _usuario.getIdUsuario() << endl;
        cout << "+-----------------------------+" << endl;
        cout << "|        MENU ENTRENADOR      |" << endl;
        cout << "+-----------------------------+" << endl;
        cout << "| 1 - HORARIOS                |" << endl;
        cout << "| 2 - RUTINAS Y EJERCICIOS    |" << endl;
        cout << "| 3 - RECLAMOS                |" << endl;
        cout << "| 4 - CAMBIAR CONTRASENIA     |" << endl;
        cout << "+-----------------------------+" << endl;
        cout << "| 0 - SALIR                   |" << endl;
        cout << "+-----------------------------+" << endl;
        cout << endl;
        cout << " Su seleccion: ";
        cin >> opcion;

        system("cls");
        switch(opcion)
        {
        case 1:
            verHorariosYSociosAsignados();
            break;
        case 2:
            crearModificarRutina();
            break;
        case 3:
            verReclamos();
            break;
        case 4:
            entrenador.modificarContrasenia(_usuario.getIdUsuario());
            break;
        case 0:
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            break;
        }

    }
    while(opcion != 0);

}

void MenuEntrenador::verHorariosYSociosAsignados()
{
    ServicioEmpleado entrenador;
    int opcion;

    do
    {
        system("cls");
        cout << "+-----------------------------------+" << endl;
        cout << "|              HORARIOS             |" << endl;
        cout << "+-----------------------------------+" << endl;
        cout << "| 1 - VER HORARIOS ASIGNADOS        |" << endl;
        cout << "| 2 - VER SOCIOS ASIGNADOS          |" << endl;
        cout << "+-----------------------------------+" << endl;
        cout << "| 0 - VOLVER ATRAS                  |" << endl;
        cout << "+-----------------------------------+" << endl;
        cout << endl;
        cout << " Su seleccion: ";
        cin >> opcion;


        system("cls");
        switch(opcion)
        {
        case 1:
            entrenador.verHorariosAsignados(_usuario.getIdUsuario());
            break;
        case 2:
            entrenador.verSociosAsignados(_usuario.getIdUsuario());
            break;
        case 0:
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            system("pause");
            break;
        }

    }
    while(opcion != 0);

}

void MenuEntrenador::crearModificarRutina()
{
    ServicioEjercicio ejercicio;
    ServicioRutina rutina;
    int opcion;

    do
    {
        system("cls");
        cout << "+--------------------------------------+" << endl;
        cout << "|               RUTINAS                |" << endl;
        cout << "+--------------------------------------+" << endl;
        cout << "| 1 - VER MIS RUTINAS                  |" << endl;
        cout << "| 2 - VER DETALLES RUTINAS             |" << endl;
        cout << "| 3 - CREAR UNA RUTINA                 |" << endl;
        cout << "| 4 - BUSCAR UNA RUTINA                |" << endl;
        cout << "| 5 - MODIFICAR UNA RUTINA             |" << endl;
        cout << "| 6 - VER EJERCICIOS                   |" << endl;
        cout << "| 7 - AGREGAR UN EJERCICIO             |" << endl;
        cout << "| 8 - MODIFICAR UN EJERCICIO           |" << endl;
        cout << "+--------------------------------------+" << endl;
        cout << "| 0 - VOLVER ATRAS                     |" << endl;
        cout << "+--------------------------------------+" << endl;
        cout << endl;
        cout << " Su seleccion: ";
        cin >> opcion;


        system("cls");
        switch(opcion)
        {
        case 1:
            rutina.verRutinas(_usuario.getIdUsuario());
            break;
        case 2:
            rutina.verDetallesDeRutina();
            break;
        case 3:
            rutina.crearRutina(_usuario.getIdUsuario());
            break;
        case 4:
            rutina.buscarRutina();
            break;
        case 5:
            rutina.mostrarOpcionesModificarRutina(_usuario.getIdUsuario());
            break;
        case 6:
            ejercicio.verEjercicios();
            break;
        case 7:
            ejercicio.agregarEjercicio();
            break;
        case 8:
            ejercicio.modificarEjercicio();
            break;
        case 0:
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            system("pause");
            break;
        }

    }
    while(opcion != 0);

}

void MenuEntrenador::verReclamos()
{
    int opcion;
    ServicioReclamo reclamo;

    do
    {
        system("cls");
        cout << "+-----------------------------------+" << endl;
        cout << "|              RECLAMOS             |" << endl;
        cout << "+-----------------------------------+" << endl;
        cout << "| 1 - REALIZAR UN RECLAMO           |" << endl;
        cout << "| 2 - VER ESTADO DE LOS RECLAMOS    |" << endl;
        cout << "+-----------------------------------+" << endl;
        cout << "| 0 - VOLVER ATRAS                  |" << endl;
        cout << "+-----------------------------------+" << endl;
        cout << endl;
        cout << " Su seleccion: ";
        cin >> opcion;


        system("cls");
        switch(opcion)
        {
        case 1:

            break;
        case 2:

            break;
        case 0:
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            system("pause");
            break;
        }

    }
    while(opcion != 0);

}
