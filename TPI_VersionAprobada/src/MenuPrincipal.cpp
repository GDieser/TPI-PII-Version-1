#include <iostream>

#include "MenuPrincipal.h"

#include "MenuSocio.h"
#include "MenuEntrenador.h"
#include "MenuGerente.h"

#include "ServicioSocio.h"
#include "ServicioEmpleado.h"
#include "ServicioAsistencia.h"
#include "usuarioAutenticado.h"
#include "autenticador.h"

using namespace std;


MenuPrincipal::MenuPrincipal()
{
    ServicioSocio sSocio;
    Autenticador autenticador;
    _usuario = autenticador.autenticar();
}

void MenuPrincipal::mostrarMenuInicio()
{

    switch(_usuario.getRol())
    {
    case 0:
    {
        cout << "Menu Gerente" << endl;
        MenuGerente menuGerente(_usuario);
        menuGerente.mostrarMenuGerente();
        break;

    }
    case 1:
    {
        cout << "Menu Entrenador" << endl;
        MenuEntrenador menuEntrenador(_usuario);
        menuEntrenador.mostrarMenuEntrenador();
        break;
    }
    case 2:
    {
        cout << "Menu Socio" << endl;
        MenuSocio menuSocio(_usuario);
        menuSocio.mostrarSubmenuSocio();
        break;
    }
    }
}
