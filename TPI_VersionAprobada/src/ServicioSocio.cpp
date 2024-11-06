#include <iostream>
#include <limits>
#include <cstring>
#include <iomanip>
<<<<<<< HEAD

=======
>>>>>>> 61682c56dbefe582e24cfc300e37a2353cffb607
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

<<<<<<< HEAD
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
=======
string ServicioSocio::membresiaToStr(int id){
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

void ServicioSocio::mostrarSociosPorEntrenador(int idEntrenador){
>>>>>>> 61682c56dbefe582e24cfc300e37a2353cffb607
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
<<<<<<< HEAD
    for (int i = 0; i < cantReg; i++)
    {
        socio = _archivoSocio.leerRegistroSocio(i);
        if(socio.getIdEntrenadorAsignado() == idEntrenador)
        {
=======
    for (int i = 0; i < cantReg; i++) {
        socio = _archivoSocio.leerRegistroSocio(i);
        if(socio.getIdEntrenadorAsignado() == idEntrenador){
>>>>>>> 61682c56dbefe582e24cfc300e37a2353cffb607
            cout << left << setw(8) <<"#"<< j << " - " << socio.getIdUsuario() << "|"
                 << setw(15) << socio.getApellido() << "|"
                 << setw(15) << socio.getNombre() << "|"
                 << setw(12) << socio.getFechaDeIngreso().toString() << "|"
                 << setw(10) << membresiaToStr(socio.getMembresia()).c_str() << "|"
                 << setw(14) << (socio.getEstado() ? "Habilitado" : "Deshabilitado") << endl;
<<<<<<< HEAD
            if ((i+24)%25 == 0 && i != 1)
            {
=======
            if ((i+24)%25 == 0 && i != 1){
>>>>>>> 61682c56dbefe582e24cfc300e37a2353cffb607
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

<<<<<<< HEAD
    for (int i = 0; i < cantReg; i++)
    {
=======
    for (int i = 0; i < cantReg; i++) {
>>>>>>> 61682c56dbefe582e24cfc300e37a2353cffb607
        socio = _archivoSocio.leerRegistroSocio(i);

        cout << left << setw(6) << socio.getIdUsuario() << "|"
             << setw(15) << socio.getApellido() << "|"
             << setw(15) << socio.getNombre() << "|"
             << setw(12) << socio.getFechaDeIngreso().toString() << "|"
             << setw(10) << membresiaToStr(socio.getMembresia()).c_str() << "|"
             << setw(14) << (socio.getEstado() ? "Habilitado" : "Deshabilitado") << endl;
<<<<<<< HEAD
        if ((i+24)%25 == 0 && i != 1)
        {
=======
        if ((i+24)%25 == 0 && i != 1){
>>>>>>> 61682c56dbefe582e24cfc300e37a2353cffb607
            system("pause");
        }
    }
    cout << string(78, '-') << endl;
    system("pause");
}

<<<<<<< HEAD
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

bool ServicioSocio::buscarSocioPorDni(int dni){

    int cantReg = _archivoSocio.cantidadRegistrosSocios();
    for(int i = 0; i < cantReg; i++){
        if(_archivoSocio.leerRegistroSocio(i).getDni() == dni){
            return true;
        }
    }
    return false;
}

=======
int ServicioSocio::autoGenerarId(){
    return 1000 + _archivoSocio.cantidadRegistrosSocios() + _archivoEmpleado.cantidadRegistrosEmpleados();
}

int ServicioSocio::seleccionarMembresia(){
    int opc;
    do{
        cout << "Ingrese 0 para FULL, 1 para SMART, 2 para FIT"<< endl;
        cin >> opc;
    } while (opc > 2 || opc < 0);
    return opc;
}

>>>>>>> 61682c56dbefe582e24cfc300e37a2353cffb607
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
<<<<<<< HEAD

    cout << "Dni: ";
    cin >> dni;
    if(buscarSocioPorDni(dni)){
        cout << "El usuario con DNI " << dni << " ya existe..." << endl;
        system("pause");
        return;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nombre: ";
    cin >> nombre;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Apellido: ";
    cin >> apellido;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
=======
    cout << "Nombre: ";
    cin >> nombre;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Para limpiar buffer de cin

    cout << "Apellido: ";
    cin >> apellido;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Para limpiar buffer de cin

    cout << "Dni: ";
    cin >> dni;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Para limpiar buffer de cin
>>>>>>> 61682c56dbefe582e24cfc300e37a2353cffb607

    cout << "Ingrese fecha nacimiento: " << endl;
    fechaNacimiento = Fecha::crearFecha();

<<<<<<< HEAD
    cout << "Contrasenia: ";
    cin >> contrasenia;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Pin: ";
    cin >> pinIngreso;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
=======
    cout << "Contraseña: ";
    cin >> contrasenia;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Para limpiar buffer de cin

    cout << "Pin: ";
    cin >> pinIngreso;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Para limpiar buffer de cin
>>>>>>> 61682c56dbefe582e24cfc300e37a2353cffb607

    idMembresia = seleccionarMembresia();

    cout << "Estado fisico: ";
    cin >> estadoFisico;
<<<<<<< HEAD
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
=======
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Para limpiar buffer de cin
>>>>>>> 61682c56dbefe582e24cfc300e37a2353cffb607

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

<<<<<<< HEAD
    if (pos == -1)
    {
=======
    if (pos == -1) {
>>>>>>> 61682c56dbefe582e24cfc300e37a2353cffb607
        cout << "Socio con id #" << idSocio << " no encontrado." << endl;
        system("pause");
        system("cls");
        return;
    }

    Socio soc = _archivoSocio.leerRegistroSocio(pos);
    cout << "A continuacion ingrese la opcion deseada: "<< endl;
    int opc;
<<<<<<< HEAD
    do
    {
=======
    do {
>>>>>>> 61682c56dbefe582e24cfc300e37a2353cffb607
        cout << string(78, '-') << endl;
        cout << "1. Modificar membresia" << endl;
        cout << "2. Cambiar rutina" << endl;
        cout << "3. Cambiar entrenador designado" << endl;
        cout << "4. Dar de baja usuario" << endl;
        cout << "0. Volver" << endl;
        cout << string(78, '-') << endl;
        cout << "Ingrese una opcion: ";
        cin >> opc;


<<<<<<< HEAD
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
=======
        switch(opc){
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
                    if (confirmacion == 'S' || confirmacion == 's') {
                        soc.setEstado(!soc.getEstado());
                        cout << "Estado de usuario cambiado." << endl;
                    } else {
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
    } while (opc != 0);
>>>>>>> 61682c56dbefe582e24cfc300e37a2353cffb607
}

void ServicioSocio::verEntrenadorAsignado(int idEntrenador)
{
    system("cls");
    int pos = _archivoEmpleado.buscarEmpleado(idEntrenador);
<<<<<<< HEAD
    if (pos == -1)
    {
=======
    if (pos == -1){
>>>>>>> 61682c56dbefe582e24cfc300e37a2353cffb607
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

<<<<<<< HEAD
Socio ServicioSocio::buscarSocioId(int idUsuario)
{

    int pos = _archivoSocio.buscarSocio(idUsuario);
    if (pos = -1)
    {
=======
Socio ServicioSocio::buscarSocioId(int idUsuario){

    int pos = _archivoSocio.buscarSocio(idUsuario);
    if (pos = -1){
>>>>>>> 61682c56dbefe582e24cfc300e37a2353cffb607
        cout << "Socio con ID #" << idUsuario << " no encontrado..." << endl;
        return Socio();
    }
    Socio socio = _archivoSocio.leerRegistroSocio(pos);
    return socio;
}

<<<<<<< HEAD
void ServicioSocio::mostrarTurno(int idTurno)
{
    cout << " Turno: ";
    switch(idTurno)
    {
    case 0:
    {
        cout << "Maniana";
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
=======
void ServicioSocio::mostrarTurno(int idTurno){
    cout << " Turno: ";
    switch(idTurno){
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
>>>>>>> 61682c56dbefe582e24cfc300e37a2353cffb607
    }
    cout << endl;
}

void ServicioSocio::verHorarios()
{

}

void ServicioSocio::verMembresia(int idUsuario)
{
    int pos = _archivoSocio.buscarSocio(idUsuario);
<<<<<<< HEAD
    if (pos == -1)
    {
=======
    if (pos == -1){
>>>>>>> 61682c56dbefe582e24cfc300e37a2353cffb607
        cout <<"Usuario no existe, intente nuevamente... " << endl;
        system("pause");
        return;
    }
    Socio socio = _archivoSocio.leerRegistroSocio(pos);


    system("cls");
    cout << "Tu membresia actual es: " << membresiaToStr(socio.getIdRol()) << endl;
    system("pause");
    system("cls");
<<<<<<< HEAD
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

    for(int i=0; i<cantReg-1; i++)
    {
        for(int j=i+1; j<cantReg; j++)
        {
            if(strcmp(socios[i].getApellido().c_str(), socios[j].getApellido().c_str()) > 0)
            {
                aux = socios[i];
                socios[i] = socios[j];
                socios[j] = aux;
            }
        }
    }
    listarSocios(socios, cantReg);
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

    for(int i=0; i<cantReg-1; i++)
    {
        for(int j=i+1; j<cantReg; j++)
        {
            if(socios[i].getDni() > socios[j].getDni())
            {
                aux = socios[i];
                socios[i] = socios[j];
                socios[j] = aux;
            }
        }
    }
    listarSocios(socios, cantReg);
    delete[] socios;

=======
>>>>>>> 61682c56dbefe582e24cfc300e37a2353cffb607
}

void ServicioSocio::modificarContrasenia(int idSocio)
{
    int pos = _archivoSocio.buscarSocio(idSocio);
<<<<<<< HEAD
    if (pos == -1)
    {
=======
    if (pos == -1) {
>>>>>>> 61682c56dbefe582e24cfc300e37a2353cffb607
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

<<<<<<< HEAD
    if (strcmp(contra1, contra2)==0)
    {
        soc.setContrasenia(contra1);
        if (_archivoSocio.guardarSocio(soc, pos))
        {
            cout << "Contraseña modificada y guardada correctamente." << endl;
        }
        else
        {
=======
    if (strcmp(contra1, contra2)==0){
        soc.setContrasenia(contra1);
         if (_archivoSocio.guardarSocio(soc, pos)) {
            cout << "Contraseña modificada y guardada correctamente." << endl;
        } else {
>>>>>>> 61682c56dbefe582e24cfc300e37a2353cffb607
            cout << "Error al guardar los cambios. Contacte al administrador del sistema..." << endl;
        }
    } else {
        cout << "Contraseñas no coinciden, intente nuevamente ..." << endl;
    }
<<<<<<< HEAD
    else
    {
        cout << "Contraseñas no coinciden, intente nuevamente ..." << endl;
    }
=======
>>>>>>> 61682c56dbefe582e24cfc300e37a2353cffb607
    system("pause");
    system("cls");
}

<<<<<<< HEAD
void ServicioSocio::mostrarFechaVencimiento(Fecha fecha)
{
=======
void ServicioSocio::mostrarFechaVencimiento(Fecha fecha) {
>>>>>>> 61682c56dbefe582e24cfc300e37a2353cffb607

    Fecha hoy = Fecha();
    int dia = fecha.getDia();
    int mes = fecha.getMes();
    int anio = fecha.getAnio();

<<<<<<< HEAD
    if (hoy.getDia() > dia)
    {
        mes++;
    }

    if (mes > 12)
    {
=======
    if (hoy.getDia() > dia) {
        mes++;
    }

    if (mes > 12) {
>>>>>>> 61682c56dbefe582e24cfc300e37a2353cffb607
        mes = 1;
        anio++;
    }

    Fecha fechaVencimiento = Fecha(dia, mes, anio);
    cout << "Su próxima cuota vence el día: " << fechaVencimiento.toString() << endl;
}
<<<<<<< HEAD

void ServicioSocio::listarSocios(Socio socios[], int cantReg)
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
=======
>>>>>>> 61682c56dbefe582e24cfc300e37a2353cffb607
