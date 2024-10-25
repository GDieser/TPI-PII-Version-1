#include <iostream>

#include "MenuEntrenador.h"
#include "ServicioEmpleado.h"
#include "ServicioReclamo.h"
#include "ServicioEjercicio.h"
#include "ServicioRutina.h"

using namespace std;


MenuEntrenador::MenuEntrenador(UsuarioAutenticado usuario) : _usuario(usuario){}

void MenuEntrenador::mostrarMenuEntrenador()
{
    int opcion;
    ServicioEmpleado entrenador;

    do
    {
        system("cls");
        cout << " ENTRENADOR: #" << _usuario.getIdUsuario() << endl;
        cout << "-------------------" <<endl;
        cout << " 1 - HORARIOS " << endl;
        cout << " 2 - RUTINAS Y EJERCICIOS" << endl;
        cout << " 3 - RECLAMOS " << endl;
        cout << " 4 - CAMBIAR CONTRASENIA " << endl;
        cout << "-------------------" <<endl;
        cout << " 0 - SALIR " << endl;
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

            break;
        case 0:
            break;
        default:
            cout << "ERROR" << endl;
            break;
        }

    }
    while(opcion != 0);

}

void MenuEntrenador::verHorariosYSociosAsignados()
{
    int opcion;

    do
    {
        system("cls");
        cout << " HORARIOS " << endl;
        cout << "---------------------------------" <<endl;
        cout << " 1 - VER HORARIOS ASIGNADOS " << endl;
        cout << " 2 - VER SOCIOS ASIGNADOS " << endl;
        cout << "---------------------------------" <<endl;
        cout << " 0 - VOLVER ATRAS " << endl;
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

void MenuEntrenador::crearModificarRutina()
{
    ServicioEjercicio ejercicio;
    ServicioRutina rutina;
    int opcion;

    do
    {
        system("cls");
        cout << " RUTINAS " << endl;
        cout << "---------------------------------" <<endl;
        cout << " 1 - VER MIS RUTINAS" << endl;
        cout << " 2 - VER DETALLES RUTINAS" << endl;
        cout << " 3 - CREAR UNA RUTINA " << endl;
        cout << " 4 - BUSCAR UNA RUTINA " << endl;///Capaz volar
        cout << " 5 - MODIFICAR UNA RUTINA " << endl;
        cout << " 6 - VER EJERCICIOS " << endl;
        cout << " 7 - AGREGAR UN EJERCICIO " << endl;
        cout << " 8 - MODIFICAR UN EJERCICIO " << endl;
        cout << "---------------------------------" <<endl;
        cout << "0 - VOLVER ATRAS " << endl;
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
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        case 8:

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
        cout << " RECLAMOS " << endl;
        cout << "---------------------------------" <<endl;
        cout << " 1 - REALIZAR UN RECLAMO " << endl;
        cout << " 2 - VER ESTADO DE UN RECLAMOS " << endl;
        cout << "---------------------------------" <<endl;
        cout << " 0 - VOLVER ATRAS " << endl;
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
