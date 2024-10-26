#include <iostream>

#include "MenuPrincipal.h"

#include "MenuSocio.h"
#include "MenuEntrenador.h"
#include "MenuGerente.h"

#include "ServicioSocio.h"
#include "ServicioEmpleado.h"
#include "ServicioAsistencia.h"

using namespace std;

MenuPrincipal::MenuPrincipal()
{

}

void MenuPrincipal::mostrarMenuInicio()
{
    int idUsuario;
    string pass;
    bool valido = false;

    cout << "ELIJA TIPO DE USUARIO: " << endl;
    cout << endl;
    cout << " 1 - SOCIO" << endl;
    cout << " 2 - ENTRENADOR" << endl;
    cout << " 3 - GERENTE" << endl;
    cout << endl;
    cout << "Su eleccion: ";

    cin >> _opcion;

    while(valido == false && _opcion > 0 && _opcion < 4)
    {
        system("cls");
        switch(_opcion)
        {
        case 1:
            valido = mostrarSubmenuSocio(idUsuario, pass);
            break;
        case 2:
            mostrarMenuLogin(idUsuario, pass);
            valido = verificarLoginEmpleado(idUsuario, pass);
            break;
        case 3:
            mostrarMenuLogin(idUsuario, pass);
            valido = verificarLoginEmpleado(idUsuario, pass);
            break;
        }
    }

    switch(_opcion)
    {
    case 2:
    {
        MenuEntrenador menuEntrenador(idUsuario);
        menuEntrenador.mostrarMenuEntrenador();
    }

    break;
    case 3:
    {
        MenuGerente menuGerente(idUsuario);
        menuGerente.mostrarMenuGerente();
    }

    break;
    }

}

void MenuPrincipal::mostrarMenuLogin(int &idUsuario, string &pass)
{
    system("cls");

    cout << "INGRESE ID: ";
    cin >> idUsuario;
    cout << "INGRESE PASS: ";
    cin >> pass;

}

bool MenuPrincipal::verificarLoginSocio(int &idUsuario, string &pass)
{

    ServicioSocio socio;

    if(socio.buscarSocioLogin(idUsuario, pass))
    {
        return true;
    }
    else
    {
        cout << "Login invalido" << endl;
        system("pause");
    }

    return false;
}

bool MenuPrincipal::verificarLoginEmpleado(int &idUsuario, string &pass)
{
    ServicioEmpleado empleado;

    if(empleado.buscarEmpleadoLogin(idUsuario, pass))
    {
        return true;
    }
    else
    {
        cout << "Login invalido" << endl;
        system("pause");
    }

    return false;
}

bool MenuPrincipal::mostrarSubmenuSocio(int &idUsuario, string &pass)
{
    bool valido = false;

    system("cls");
    int opcion;
    int intentos = 0;

    cout << " -- SELECCION DE INGRESO -- " << endl;
    cout << endl;
    cout << " 1 - Ingreso al Gimnasio " << endl;
    cout << " 2 - Ingreso al Menu Socio " << endl;
    cout << endl;
    cout << "Su seleccion: ";
    cin >> opcion;

    if(opcion == 1)
    {
        while(intentos < 3 && valido == false)
        {
            valido = mostrarMenuIngresoSocio();
            return valido;
        }
    }
    else
    {
        while(intentos < 3 && valido == false)
        {
            mostrarMenuLogin(idUsuario, pass);
            valido = verificarLoginSocio(idUsuario, pass);
            intentos++;
        }
    }
    if(valido)
    {
        MenuSocio menuSocio(idUsuario);
        menuSocio.mostrarMenuSocio();

        return valido;
    }
}

bool MenuPrincipal::mostrarMenuIngresoSocio()
{
    ServicioSocio socio;
    ServicioAsistencia asistencia;

    bool valido;
    int idUsuario;
    int pin;

    system("cls");

    cout << " ID: ";
    cin >> idUsuario;
    cout << " PIN: ";
    cin >> pin;

    if(socio.validarLoginAsistenciaSocio(idUsuario, pin))
    {
        system("cls");
        cout << "Bienvenido" << endl;
        system("pause");

        asistencia.registrarAsistencia(idUsuario);

        return true;
    }

}
