#include <iostream>
#include <cstring>

#include "autenticador.h"
#include "Usuario.h"
#include "GestionArchivoEmpleados.h"
#include "GestionArchivoSocios.h"

using namespace std;

UsuarioAutenticado Autenticador::autenticar()
{
    int idUsuario;
    string pass;
    char _pass[50];

    system("cls");

    cout << "INGRESE ID: ";
    cin >> idUsuario;
    cout << "INGRESE PASS: ";
    cin >> pass;

    strncpy(_pass, pass.c_str(), 49);

    Usuario usuario = buscarUsuario(idUsuario, _pass);

    if (usuario.getEstado())
    {
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
    }

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

    cout << "Contraseña o usuario inexistente..." << endl;

    return Usuario();
}
