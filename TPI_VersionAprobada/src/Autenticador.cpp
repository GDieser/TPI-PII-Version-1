#include <iostream>
#include <cstring>

#include "autenticador.h"
#include "Usuario.h"
#include "GestionArchivoEmpleados.h"
#include "GestionArchivoSocios.h"

using namespace std;

UsuarioAutenticado Autenticador::autenticar()
{
    Usuario usuario;
    int idUsuario;
    string pass;
    char _pass[50];
    int contador = 0;

    do
    {
        system("cls");

        cout << "+--------------------------------------+" << endl;
        cout << "|         Bienvenido a MetalGYM        |" << endl;
        cout << "|      El Camino a tu mejor version    |" << endl;
        cout << "+--------------------------------------+" << endl;
        cout << endl;

        cout << "       Ingrese sus datos de acceso     " << endl;
        cout << endl;

        cout << " INGRESE ID: ";
        cin >> idUsuario;

        cout << " INGRESE PASS: ";
        cin >> pass;

        cout << endl;
        cout << "+--------------------------------------+" << endl;
        cout << "|   Gracias por ingresar, cargando...  |" << endl;
        cout << "+--------------------------------------+" << endl;
        system("pause");

        strncpy(_pass, pass.c_str(), 49);

        usuario = buscarUsuario(idUsuario, _pass);
        contador++;
    }
    while(contador < 3 && usuario.getIdUsuario() != idUsuario );

    if(contador == 3)
    {
        system("cls");
        cout << "+--------------------------------------+" << endl;
        cout << "|    Limites de intentos alcanzado     |" << endl;
        cout << "|  Intente nuevamente en unos minutos  |" << endl;
        cout << "+--------------------------------------+" << endl;
    }

    UsuarioAutenticado authUs(
        usuario.getIdUsuario(),
        usuario.getNombre(),
        usuario.getApellido(),
        usuario.getDni(),
        usuario.getFechaNacimiento(),
        usuario.getFechaDeIngreso(),
        usuario.getIdRol(),
        usuario.getEstado()
    );
    return authUs;


    return UsuarioAutenticado();
}

Usuario Autenticador::buscarUsuario(const int idUsuario, const char* pass)
{
    GestionArchivoEmpleados empleados("archivoEmpleados.dat");
    int posEmpleado = empleados.buscarEmpleado(idUsuario);
    if (posEmpleado != -1)
    {
        Empleado emp = empleados.leerRegistroEmpleado(posEmpleado);
        if (strcmp(emp.getContrasenia().c_str(), pass) == 0)
        {
            return emp;
        }
    }

    GestionArchivoSocios socios("archivoSocios.dat");
    int posSocio = socios.buscarSocio(idUsuario);
    if (posSocio != -1)
    {
        Socio soc = socios.leerRegistroSocio(posSocio);
        if (strcmp(soc.getContrasenia().c_str(), pass) == 0)
        {
            return soc;
        }
    }

    system("cls");
    cout << "+--------------------------------------+" << endl;
    cout << "|   Contrasenia o usuario incorrectos  |" << endl;
    cout << "|          Pruebe nuevamente           |" << endl;
    cout << "+--------------------------------------+" << endl;
    system("pause");


    return Usuario();
}
