#include <iostream>

#include "MenuGerente.h"

#include "ServicioSocio.h"
#include "ServicioEmpleado.h"
#include "ServicioReclamo.h"
#include "ServicioPago.h"

using namespace std;

MenuGerente::MenuGerente(UsuarioAutenticado usuario) : _usuario(usuario){}

void MenuGerente::mostrarMenuGerente()
{
    int opcion;

    do
    {
        system("cls");
        cout << "  GERENTE: #" << _usuario.getIdUsuario()  << endl;
        cout << "+--------------------------------------+" << endl;
        cout << "|             MENU GERENTE             |" << endl;
        cout << "+--------------------------------------+" << endl;
        cout << "| 1 - GESTIONAR SOCIOS                 |" << endl;
        cout << "| 2 - GESTIONAR ENTRENADORES           |" << endl;
        cout << "| 3 - GESTIONAR GERENTE                |" << endl;
        cout << "| 4 - GESTIONAR PAGOS                  |" << endl;
        cout << "| 5 - GESTIONAR RECLAMOS               |" << endl;
        cout << "| 6 - VER ESTADISTICAS                 |" << endl;
        cout << "+--------------------------------------+" << endl;
        cout << "| 0 - SALIR                            |" << endl;
        cout << "+--------------------------------------+" << endl;
        cout << endl;
        cout << " Su seleccion: ";
        cin >> opcion;

        system("cls");
        switch(opcion)
        {
        case 1:
            gestionarSocios();
            break;
        case 2:
            gestionarEntrenadores();
            break;
        case 3:
            gestionarGerentes();

            break;
        case 4:
            gestionarPagos();

            break;
        case 5:
            gestionarReclamos();

            break;
        case 6:
            verEstadisticas();
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

void MenuGerente::gestionarSocios()
{
    int opcion;
    ServicioSocio socio;

    do
    {
        system("cls");
        cout << "+----------------------------------------+" << endl;
        cout << "|                SOCIOS                  |" << endl;
        cout << "+----------------------------------------+" << endl;
        cout << "| 1 - VER LISTA DE SOCIOS ACTIVOS        |" << endl;
        cout << "| 2 - AGREGAR NUEVO SOCIO                |" << endl;
        cout << "| 3 - MODIFICAR SOCIO                    |" << endl;
        cout << "| 4 - BUSCAR SOCIO                       |" << endl;
        cout << "| 5 - RESTAURAR SOCIO                    |" << endl;///Dentro de modificar?
        cout << "| 6 - ASIGNAR ENTRENADOR                 |" << endl;
        cout << "+----------------------------------------+" << endl;
        cout << "| 0 - VOLVER ATRAS                       |" << endl;
        cout << "+----------------------------------------+" << endl;
        cout << endl;
        cout << " Su seleccion: ";
        cin >> opcion;

        system("cls");
        switch(opcion)
        {
        case 1:
            socio.verSocios();
            break;
        case 2:
            socio.agregarSocio();
            break;
        case 3:
            ///socio.modificarSocio(); //Deberia pedir el ID dentro
            break;
        case 4:
            ///socio.buscarSocioId(); //Deberia pedir el ID dentro
            break;
        case 5:
            ///Dentro de modificar?
            break;
        case 6:

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
void MenuGerente::gestionarEntrenadores()
{
    int opcion;
    ServicioEmpleado entrenador;

    do
    {
        system("cls");
        cout << "+--------------------------------------------+" << endl;
        cout << "|                ENTRENADORES                |" << endl;
        cout << "+--------------------------------------------+" << endl;
        cout << "| 1 - VER LISTA DE ENTRENADORES ACTIVOS      |" << endl;
        cout << "| 2 - AGREGAR NUEVO ENTRENADOR               |" << endl;
        cout << "| 3 - MODIFICAR ENTRENADOR                   |" << endl;
        cout << "| 4 - BUSCAR ENTRENADOR                      |" << endl;
        cout << "| 5 - RESTAURAR ENTRENADOR                   |" << endl;
        cout << "| 6 - ASIGNAR HORARIOS                       |" << endl;
        cout << "+--------------------------------------------+" << endl;
        cout << "| 0 - VOLVER ATRAS                           |" << endl;
        cout << "+--------------------------------------------+" << endl;
        cout << endl;
        cout << " Su seleccion: ";
        cin >> opcion;


        system("cls");
        switch(opcion)
        {
        case 1:
            //entrenador.listarEmpleadoPorApellido(1);
            //entrenador.mostrarHorariosDeEntrenadores();
            entrenador.verEmpleados(1);
            break;
        case 2:
            entrenador.agregarEmpleado(1);
            break;
        case 3:
            entrenador.modificarEmpleado(1);
            break;
        case 4:
            entrenador.buscarUnEmpleado(1);
            break;
        case 5:
            entrenador.restaurarUnEmpleado(1);
            break;
        case 6:
            entrenador.asignarHorarios();
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
void MenuGerente::gestionarGerentes()
{
    int opcion;
    ServicioEmpleado gerente;

    do
    {
        system("cls");
        cout << "+----------------------------------------+" << endl;
        cout << "|                GERENTES                |" << endl;
        cout << "+----------------------------------------+" << endl;
        cout << "| 1 - VER LISTA DE GERENTES              |" << endl;
        cout << "| 2 - AGREGAR NUEVO GERENTE              |" << endl;
        cout << "| 3 - MODIFICAR GERENTE                  |" << endl;
        cout << "| 4 - BUSCAR GERENTE                     |" << endl;
        cout << "| 5 - RESTAURAR GERENTE                  |" << endl;
        cout << "| 6 - CAMBIAR CONTRASENIA                |" << endl;
        cout << "+----------------------------------------+" << endl;
        cout << "| 0 - VOLVER ATRAS                       |" << endl;
        cout << "+----------------------------------------+" << endl;
        cout << endl;
        cout << " Su seleccion: ";
        cin >> opcion;


        system("cls");
        switch(opcion)
        {
        case 1:
            gerente.verEmpleados(0);
            break;
        case 2:
            gerente.agregarEmpleado(0);
            break;
        case 3:
            gerente.modificarContrasenia(0);
            break;
        case 4:
            gerente.buscarUnEmpleado(0);
            break;
        case 5:
            gerente.restaurarUnEmpleado(0);
            break;
        case 6:
            gerente.modificarContrasenia(_usuario.getIdUsuario());
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
void MenuGerente::gestionarPagos()
{
    int opcion;
    ServicioPago pago;

    do
    {
        system("cls");
        cout << "+----------------------------------------+" << endl;
        cout << "|            PAGOS DE SOCIOS             |" << endl;
        cout << "+----------------------------------------+" << endl;
        ///cout << "| 1 - VER LISTA DE PAGOS PENDIENTES      |" << endl; /// Capaz volar
        cout << "| 1 - VER LISTA DE PAGOS POR MES         |" << endl;
        cout << "| 2 - VER LISTA DE PAGOS POR ANIO        |" << endl;
        cout << "| 3 - VER LISTA POR TIPOS DE PASES       |" << endl;
        ///cout << "| 5 - LISTA DE DEUDORES                  |" << endl; /// Capaz volar
        cout << "+----------------------------------------+" << endl;
        cout << "| 0 - VOLVER ATRAS                       |" << endl;
        cout << "+----------------------------------------+" << endl;
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

void MenuGerente::gestionarReclamos()
{
    int opcion;
    ServicioReclamo reclamo;

    do
    {
        system("cls");
        cout << "+-------------------------------------------+" << endl;
        cout << "|                 RECLAMOS                  |" << endl;
        cout << "+-------------------------------------------+" << endl;
        cout << "| 1 - VER LISTA DE RECLAMOS ACTIVOS         |" << endl;
        cout << "| 2 - VER LISTA DE RECLAMOS RESUELTOS       |" << endl;
        cout << "| 3 - MODIFICAR RECLAMO                     |" << endl;
        cout << "+-------------------------------------------+" << endl;
        cout << "| 0 - VOLVER ATRAS                          |" << endl;
        cout << "+-------------------------------------------+" << endl;
        cout << endl;
        cout << " Su seleccion: ";
        cin >> opcion;


        system("cls");
        switch(opcion)
        {
        case 1:
            reclamo.mostrarReclamo(false);
            break;
        case 2:
            reclamo.mostrarReclamo(true);
            break;
        case 3:
            reclamo.cambiarEstadoReclamo();
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
void MenuGerente::verEstadisticas()
{
    int opcion;

    ServicioPago pago;
    do
    {
        system("cls");
        cout << "+---------------------------------------------+" << endl;
        cout << "|                 ESTADISTICAS                |" << endl;
        cout << "+---------------------------------------------+" << endl;
        cout << "| 1 - VER ESTADISTICAS DE INGRESOS POR ANIO   |" << endl;
        cout << "| 2 - VER ESTADISTICA DE INGRESOS POR MES     |" << endl;
        cout << "+---------------------------------------------+" << endl;
        cout << "| 0 - VOLVER ATRAS                            |" << endl;
        cout << "+---------------------------------------------+" << endl;
        cout << endl;
        cout << " Su seleccion: ";
        cin >> opcion;


        system("cls");
        switch(opcion)
        {
        case 1:
            pago.verIngresosAnuales();
            break;
        case 2:
            pago.verIngresosMensuales();
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

