#include <iostream>

#include "MenuSocio.h"
#include "ServicioPago.h"
#include "ServicioReclamo.h"
#include "ServicioAsistencia.h"
#include "GestionArchivoSocios.h"
#include "ServicioRutina.h"

using namespace std;

MenuSocio::MenuSocio(UsuarioAutenticado usuario) : _usuario(usuario), _sSocio()
{
}

void MenuSocio::mostrarSubmenuSocio()
{
    system("cls");
    int opcion;
    cout << " -- BIENVENIDO "<< _usuario.getNombre() << " -- " << endl;
    cout << endl;
    cout << " 1 - Ingreso al Gimnasio " << endl;
    cout << " 2 - Ingreso al Menu Socio " << endl;
    cout << endl;
    cout << "Su seleccion: ";
    cin >> opcion;

    if(opcion == 1)
    {
        mostrarMenuIngresoSocio();
    }
    else
    {
        mostrarMenuSocio();
    }
}

void MenuSocio::mostrarMenuIngresoSocio()
{

    ServicioSocio socio;
    ServicioAsistencia asistencia;

    system("cls");
    cout << "Bienvenido" << _usuario.getNombre() << endl;
    asistencia.registrarAsistencia(_usuario.getIdUsuario());
    mostrarSubmenuSocio();
}

void MenuSocio::mostrarMenuSocio()
{
    int opcion;
    ServicioSocio socio;

    do
    {
        system("cls");
        cout << " MENU SOCIO: #" << _usuario.getIdUsuario() << endl;
        cout << "-------------------------------" << endl;
        cout << " 1 - PAGOS " << endl;
        cout << " 2 - RUTINAS " << endl;
        cout << " 3 - HORARIOS " << endl;
        cout << " 4 - RECLAMOS " << endl;
        cout << " 5 - CAMBIAR CONTRASENIA " << endl;
        cout << "-------------------------------" << endl;
        cout << " 0 - SALIR " << endl;
        cout << endl;
        cout << " Su seleccion: ";
        cin >> opcion;

        system("cls");
        switch(opcion)
        {
        case 1:
            gestionarPagos();
            break;
        case 2:
            verRutina();
            break;
        case 3:
            consultarHorarios();
            break;
        case 4:
            presentarReclamo();
            break;
        case 5:
            _sSocio.modificarContrasenia(_usuario.getIdUsuario());
            break;
        case 0:
            cout << "ADIOS!" << endl;
            system("pause");
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            break;
        }

    }
    while(opcion != 0);
}

void MenuSocio::gestionarPagos()
{
    int opcion;
    ServicioSocio socio;
    ServicioPago sPago;

    do
    {
        system("cls");
        cout << " PAGOS" << endl;
        cout << "-------------------------------" << endl;
        cout << " 1 - REALIZAR UN PAGO " << endl;
        cout << " 2 - VER PAGOS ANTERIORES " << endl;
        cout << " 3 - VER FECHA DE VENCIMIENTO " << endl;
        cout << " 4 - VER PRECIOS DIFERENTES PASES " << endl;
        cout << " 5 - VER MI MEMBRESIA" << endl;
        cout << "-------------------------------" << endl;
        cout << " 0 - VOLVER ATRAS " << endl;
        cout << endl;
        cout << " Su seleccion: ";
        cin >> opcion;


        system("cls");
        switch(opcion)
        {
        case 1:
            //sPago.registrarPago();
            break;
        case 2:
            //sPago.mostrarRegistroPagos(int idSocio);
            break;
        case 3:

            break;
        case 4:
            mostrarPreciosDePases();
            break;
        case 5:
            _sSocio.verMembresia(_usuario.getIdUsuario());
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            break;
        }

    }
    while(opcion != 0);

}


void MenuSocio::mostrarPreciosDePases()
{
    system("cls");
    cout << endl;
    cout << "+-------------------------+" << endl;
    cout << "| - Pase Full : $55.000 - |" << endl;
    cout << "| - Pase Smart: $35.000 - |" << endl;
    cout << "| - Pase Fit  : $25.000 - |" << endl;
    cout << "+-------------------------+" << endl;

    system("pause");
}

void MenuSocio::verRutina()
{
    int opcion;
    ServicioSocio socio;

    do
    {
        system("cls");
        cout << " RUTINAS " << endl;
        cout << "-------------------------------" << endl;
        cout << " 1 - VER MI RUTINA " << endl;
        cout << "-------------------------------" << endl;
        cout << " 0 - VOLVER ATRAS " << endl;
        cout << endl;
        cout << " Su seleccion: ";
        cin >> opcion;


        system("cls");
        switch(opcion)
        {
        case 1:
            {
                ServicioRutina sRutina;
                Socio socio = _sSocio.buscarSocioId(_usuario.getIdUsuario());
                //serRutina.verDetallesDeRutina(_usuario.getIdRutina());
                break;
            }

        default:
            cout << "ERROR" << endl;
            break;
        }

    }
    while(opcion != 0);

}

void MenuSocio::consultarHorarios()
{
    int opcion;
    ServicioSocio socio;

    do
    {
        system("cls");
        cout << " HORARIOS" << endl;
        cout << "-----------------------------------------" << endl;
        cout << " 1 - VER HORARIOS DE ENTRENAMIENTOS " << endl;
        cout << " 2 - VER MIS INSCRIPCIONES " << endl;
        cout << " 3 - VER HORARIOS DE APERTURA Y CIERRE " << endl;
        cout << "-----------------------------------------" << endl;
        cout << " 0 - VOLVER ATRAS " << endl;
        cout << endl;
        cout << "Su seleccion: ";
        cin >> opcion;


        system("cls");
        switch(opcion)
        {
        case 1:

            break;
        case 2:

            break;
        case 3:
            verHorariosGimnasio();
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            break;
        }

    }
    while(opcion != 0);

}

void MenuSocio::verHorariosGimnasio()
{
    system("cls");
    cout << endl;
    cout << "+--------------------------+" << endl;
    cout << "|  HORARIOS DEL GIMNASIO   |" << endl;
    cout << "|                          |" << endl;
    cout << "|  LUN a DOM 08hs a 00hs   |" << endl;
    cout << "+--------------------------+" << endl;
    system("pause");
}


void MenuSocio::presentarReclamo()
{
    int opcion;
    ServicioReclamo reclamo;

    do
    {
        system("cls");
        cout << " RECLAMOS" << endl;
        cout << "-------------------------------" << endl;
        cout << " 1 - REALIZAR UN RECLAMO " << endl;
        cout << " 2 - VER ESTADO DE UN RECLAMOS " << endl;
        cout << "-------------------------------" << endl;
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
        default:
            cout << "ERROR" << endl;
            break;
        }

    }
    while(opcion != 0);

}
