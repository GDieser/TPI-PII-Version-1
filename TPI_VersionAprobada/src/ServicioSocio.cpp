#include <iostream>
#include <limits>
#include <cstring>
#include <iomanip>
#include "ServicioSocio.h"
#include "Socio.h"
#include "Fecha.h"
#include "ServicioEmpleado.h"
#include "ServicioPago.h"
#include "ServicioRutina.h"
#include "ServicioActividad.h"

using namespace std;


ServicioSocio::ServicioSocio()
{
    _archivoSocio = GestionArchivoSocios("archivoSocios.dat");
    _archivoEmpleado = GestionArchivoEmpleados("archivoEmpleados.dat");
}

string ServicioSocio::membresiaToStr(int id)
{
    string memb;
    switch (id)
    {
    case 0:
    {
        memb = "FULL";
        break;
    }
    case 1:
    {
        memb = "SMART";
        break;
    }
    case 2:
    {
        memb = "FIT";
        break;
    }
    }
    return memb;
}

void ServicioSocio::mostrarSociosPorEntrenador(int idEntrenador)
{
    int cantReg = _archivoSocio.cantidadRegistrosSocios();
    Socio socio;
    cout << "Socios encontrados: " << cantReg << " socios." << endl;
    cout << string(78, '-') << endl;
    cout << left << setw(8) << "ID" << "|"
         << setw(15) << "Apellido" << "|"
         << setw(15) << "Nombre" << "|"
         << setw(12) << "Fecha Ing." << "|"
         << setw(10) << "Membresia" << "|"
         << setw(14) << "Estado" << endl;
    cout << string(78, '-') << endl;
    int j = 0;
    for (int i = 0; i < cantReg; i++)
    {
        socio = _archivoSocio.leerRegistroSocio(i);
        if(socio.getIdEntrenadorAsignado() == idEntrenador)
        {
            cout << left << setw(8) <<"#"<< j << " - " << socio.getIdUsuario() << "|"
                 << setw(15) << socio.getApellido() << "|"
                 << setw(15) << socio.getNombre() << "|"
                 << setw(12) << socio.getFechaDeIngreso().toString() << "|"
                 << setw(10) << membresiaToStr(socio.getMembresia()).c_str() << "|"
                 << setw(14) << (socio.getEstado() ? "Habilitado" : "Deshabilitado") << endl;
            if ((i+24)%25 == 0 && i != 1)
            {
                system("pause");
            }
            j++;
        }
    }
    cout << string(78, '-') << endl;
    system("pause");

}

void ServicioSocio::verSocios()
{
    int cantReg = _archivoSocio.cantidadRegistrosSocios();
    Socio socio;

    cout << string(78, '-') << endl;
    cout << left << setw(6) << "ID" << "|"
         << setw(15) << "Apellido" << "|"
         << setw(15) << "Nombre" << "|"
         << setw(12) << "Fecha Ing." << "|"
         << setw(10) << "Membresia" << "|"
         << setw(14) << "Estado" << endl;
    cout << string(78, '-') << endl;

    for (int i = 0; i < cantReg; i++)
    {
        socio = _archivoSocio.leerRegistroSocio(i);

        cout << left << setw(6) << socio.getIdUsuario() << "|"
             << setw(15) << socio.getApellido() << "|"
             << setw(15) << socio.getNombre() << "|"
             << setw(12) << socio.getFechaDeIngreso().toString() << "|"
             << setw(10) << membresiaToStr(socio.getMembresia()).c_str() << "|"
             << setw(14) << (socio.getEstado() ? "Habilitado" : "Deshabilitado") << endl;
        if ((i+24)%25 == 0 && i != 1)
        {
            system("pause");
        }
    }
    cout << string(78, '-') << endl;
    system("pause");
}

int ServicioSocio::autoGenerarId()
{
    return 1000 + _archivoSocio.cantidadRegistrosSocios() + _archivoEmpleado.cantidadRegistrosEmpleados();
}

int ServicioSocio::seleccionarMembresia()
{
    int opc;
    do
    {
        cout << "Ingrese 0 para FULL, 1 para SMART, 2 para FIT"<< endl;
        cin >> opc;
    }
    while (opc > 2 || opc < 0);
    return opc;
}

void ServicioSocio::agregarSocio()
{
    string nombre;
    string apellido;
    int dni;
    int idUsuario = autoGenerarId();
    Fecha fechaNacimiento;
    Fecha fechaIngreso;
    string contrasenia;
    bool estado = true;
    int idRol = 2;
    int idMembresia;
    string estadoFisico;
    int idRutina;
    int idEntrenadorAsignado;
    int pinIngreso;

    ServicioEmpleado servicioEmpleado;
    ServicioRutina servicioRutina;

    cout << "A continuacion lo guiaremos en el proceso para agregar un nuevo socio..." << endl;
    cout << string(70, '-') << endl;
    cout << "Nombre: ";
    cin >> nombre;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Para limpiar buffer de cin

    cout << "Apellido: ";
    cin >> apellido;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Para limpiar buffer de cin

    cout << "Dni: ";
    cin >> dni;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Para limpiar buffer de cin

    cout << "Ingrese fecha nacimiento: " << endl;
    fechaNacimiento = Fecha::crearFecha();

    cout << "Contraseña: ";
    cin >> contrasenia;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Para limpiar buffer de cin

    cout << "Pin: ";
    cin >> pinIngreso;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Para limpiar buffer de cin

    idMembresia = seleccionarMembresia();

    cout << "Estado fisico: ";
    cin >> estadoFisico;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Para limpiar buffer de cin

    idRutina = 1; //servicioRutina.elegirRutina();
    idEntrenadorAsignado = 1; //servicioEmpleado.elegirEntrenador();

    cout << string(78, '-') << endl;

    Socio socio(nombre, apellido, dni, idUsuario, fechaNacimiento, fechaIngreso, contrasenia,
                estado, idRol, idMembresia, estadoFisico, idRutina, idEntrenadorAsignado, pinIngreso);

    _archivoSocio.guardarSocio(socio);
    cout << "Socio ingresado correctamente!" << endl;
    cout << string(78, '-') << endl;

    system("pause");
}

void ServicioSocio::modificarSocio(int idSocio)
{
    int pos = _archivoSocio.buscarSocio(idSocio);

    if (pos == -1)
    {
        cout << "Socio con id #" << idSocio << " no encontrado." << endl;
        system("pause");
        system("cls");
        return;
    }

    Socio soc = _archivoSocio.leerRegistroSocio(pos);
    cout << "A continuacion ingrese la opcion deseada: "<< endl;
    int opc;
    do
    {
        cout << string(78, '-') << endl;
        cout << "1. Modificar membresia" << endl;
        cout << "2. Cambiar rutina" << endl;
        cout << "3. Cambiar entrenador designado" << endl;
        cout << "4. Dar de baja usuario" << endl;
        cout << "0. Volver" << endl;
        cout << string(78, '-') << endl;
        cout << "Ingrese una opcion: ";
        cin >> opc;


        switch(opc)
        {
        case 1:
        {
            soc.setMembresia(seleccionarMembresia());
            break;
        }
        case 2:
        {
            soc.setIdRutina(1); //Se debe utilizar servicioRutina.elegirRutina())
            break;
        }
        case 3:
        {
            soc.setIdEntrenadorAsignado(1); //Se debe utilizar servicioEmpleado.elegirEntrenador())
            break;
        }
        case 4:
        {
            cout << "¿Está seguro de cambiar el estado de este usuario? (S/N): ";
            char confirmacion;
            cin >> confirmacion;
            if (confirmacion == 'S' || confirmacion == 's')
            {
                soc.setEstado(!soc.getEstado());
                cout << "Estado de usuario cambiado." << endl;
            }
            else
            {
                cout << "Cambio de estado cancelado." << endl;
            }
            break;
        }
        case 0:
        {
            break;
        }
        default:
        {
            cout << "Debe ingresar una opcion valida" << endl;
            break;
        }
        }
    }
    while (opc != 0);
}

void ServicioSocio::verEntrenadorAsignado(int idEntrenador)
{
    system("cls");
    int pos = _archivoEmpleado.buscarEmpleado(idEntrenador);
    if (pos == -1)
    {
        cout << "No se encuentra entrenador con ID #" << idEntrenador << endl;
        system("pause");
        return;
    }
    ServicioActividad sActividad;
    Empleado emp = _archivoEmpleado.leerRegistroEmpleado(pos);
    cout << "+ -------t SU ENTRENADOR \t------- +" << endl;
    cout << "| Nombre: \t" << emp.getNombre() <<"\t|" <<  endl;
    cout << "| Apellido: \t" << emp.getApellido()<<"\t|" << endl;
    //cout << " Actividad: \t" << sActividad.verActividad(emp.getIdActividadPrincipal()) << endl; -- DESCOMENTAR una vez finalizado
    cout << "| Dias: " << emp.getDiaSem()<<"\t|" << endl;
    cout << "+ -------\t ------- \t------- +" << endl;

    mostrarTurno(emp.getIdTurno());

    system("pause");
}

Socio ServicioSocio::buscarSocioId(int idUsuario)
{

    int pos = _archivoSocio.buscarSocio(idUsuario);
    if (pos = -1)
    {
        cout << "Socio con ID #" << idUsuario << " no encontrado..." << endl;
        return Socio();
    }
    Socio socio = _archivoSocio.leerRegistroSocio(pos);
    return socio;
}

void ServicioSocio::mostrarTurno(int idTurno)
{
    cout << " Turno: ";
    switch(idTurno)
    {
    case 0:
    {
        cout << "Mañana";
        break;
    }
    case 1:
    {
        cout << "Tarde";
        break;
    }
    case 2:
    {
        cout << "Noche";
        break;
    }
    }
    cout << endl;
}

void ServicioSocio::verHorarios()
{

}

void ServicioSocio::verMembresia(int idUsuario)
{
    int pos = _archivoSocio.buscarSocio(idUsuario);
    if (pos == -1)
    {
        cout <<"Usuario no existe, intente nuevamente... " << endl;
        system("pause");
        return;
    }
    Socio socio = _archivoSocio.leerRegistroSocio(pos);


    system("cls");
    cout << "Tu membresia actual es: " << membresiaToStr(socio.getIdRol()) << endl;
    system("pause");
    system("cls");
}

void ServicioSocio::verSociosPorApellido()
{
    Socio* socios;
    int cantReg = _archivoSocio.cantidadRegistrosSocios();

    socios = new Socio[cantReg];
    if (socios == nullptr){
        cout << "Error al leer el archivo de socios..." << endl;
        return;
    }
    cout << string(78, '-') << endl;
    cout << "Socios ordenados por apellido: " << endl;
    cout << string(78, '-') << endl;
    for(int i=0; i<cantReg; i++)
    {
        socios[i] = _archivoSocio.leerRegistroSocio(i);
    }
    Socio aux;

    ///Ordenamiento por intercambio o SWAP, similar al burbujeo, sacado del libro pag 428
    for(i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmp(socios[i].getApellido().c_str(), socios[j].getApellido().c_str()) > 0)
            {
                aux = socios[i];
                socios[i] = socios[j];
                socios[j] = aux;
            }
        }
    }
    mostrarSocios(socios, cantReg);
    delete[] socios;

}

void ServicioSocio::verSociosPorDni()
{
    Socio* socios;
    int cantReg = _archivoSocio.cantidadRegistrosSocios();

    socios = new Socio[cantReg];
    if (socios == nullptr){
        cout << "Error al leer el archivo de socios..." << endl;
        return;
    }
    cout << string(78, '-') << endl;
    cout << "Socios ordenados por DNI: " << endl;
    cout << string(78, '-') << endl;
    for(int i=0; i<cantReg; i++)
    {
        socios[i] = _archivoSocio.leerRegistroSocio(i);
    }
    Socio aux;

    ///Ordenamiento por intercambio o SWAP, similar al burbujeo, sacado del libro pag 428
    for(i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(socios[i].getDni() > socios[j].getDni())
            {
                aux = socios[i];
                socios[i] = socios[j];
                socios[j] = aux;
            }
        }
    }
    mostrarSocios(socios, cantReg);
    delete[] socios;

}

void ServicioSocio::modificarContrasenia(int idSocio)
{
    int pos = _archivoSocio.buscarSocio(idSocio);
    if (pos == -1)
    {
        cout << "Socio con id #" << idSocio << " no encontrado." << endl;
        return;
    }

    Socio soc = _archivoSocio.leerRegistroSocio(pos);
    char contra1[50], contra2[50];

    cout << "Ingrese su nueva contraseña: ";
    cin >> contra1;
    cout << "Repita nuevamente su contraseña: ";
    cin >> contra2;

    contra1[sizeof(contra1)-1] = '\0';
    contra2[sizeof(contra2)-1] = '\0';

    if (strcmp(contra1, contra2)==0)
    {
        soc.setContrasenia(contra1);
        if (_archivoSocio.guardarSocio(soc, pos))
        {
            cout << "Contraseña modificada y guardada correctamente." << endl;
        }
        else
        {
            cout << "Error al guardar los cambios. Contacte al administrador del sistema..." << endl;
        }
    }
    else
    {
        cout << "Contraseñas no coinciden, intente nuevamente ..." << endl;
    }
    system("pause");
    system("cls");
}

void ServicioSocio::mostrarFechaVencimiento(Fecha fecha)
{

    Fecha hoy = Fecha();
    int dia = fecha.getDia();
    int mes = fecha.getMes();
    int anio = fecha.getAnio();

    if (hoy.getDia() > dia)
    {
        mes++;
    }

    if (mes > 12)
    {
        mes = 1;
        anio++;
    }

    Fecha fechaVencimiento = Fecha(dia, mes, anio);
    cout << "Su próxima cuota vence el día: " << fechaVencimiento.toString() << endl;
}

void listarSocios(Socio socios[], int cantReg)
{
    Socio socio;

    cout << string(78, '-') << endl;
    cout << left << setw(6) << "ID" << "|"
         << setw(15) << "Apellido" << "|"
         << setw(15) << "Nombre" << "|"
         << setw(12) << "Fecha Ing." << "|"
         << setw(10) << "Membresia" << "|"
         << setw(14) << "Estado" << endl;
    cout << string(78, '-') << endl;

    for (int i = 0; i < cantReg; i++)
    {
        socio = socios[i];

        cout << left << setw(6) << socio.getIdUsuario() << "|"
             << setw(15) << socio.getApellido() << "|"
             << setw(15) << socio.getNombre() << "|"
             << setw(12) << socio.getFechaDeIngreso().toString() << "|"
             << setw(10) << membresiaToStr(socio.getMembresia()).c_str() << "|"
             << setw(14) << (socio.getEstado() ? "Habilitado" : "Deshabilitado") << endl;
        if ((i+24)%25 == 0 && i != 1)
        {
            system("pause");
        }
    }
    cout << string(78, '-') << endl;
    system("pause");
}
