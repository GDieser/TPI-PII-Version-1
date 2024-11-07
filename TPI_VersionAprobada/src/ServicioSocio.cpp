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
        memb = "FULL ";
        break;
    }
    case 1:
    {
        memb = "SMART";
        break;
    }
    case 2:
    {
        memb = "FIT  ";
        break;
    }
    }
    return memb;
}

void ServicioSocio::mostrarSociosPorEntrenador(int idEntrenador)
{
    int contador = 0;
    int cantReg = _archivoSocio.cantidadRegistrosSocios();
    Socio socio;

    cout << string(78, '-') << endl;
    cout << left << setw(8) << "ID" << "|"
         << setw(15) << "Apellido" << "|"
         << setw(15) << "Nombre" << "|"
         << setw(12) << "Fecha Ing." << "|"
         << setw(10) << "Membresia" << "|"
         << setw(14) << "Estado" << endl;
    cout << string(78, '-') << endl;
    int j = 1;
    for (int i = 0; i < cantReg; i++)
    {
        socio = _archivoSocio.leerRegistroSocio(i);
        if(socio.getIdEntrenadorAsignado() == idEntrenador)
        {
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
            j++;
            contador++;
        }
    }
    if(contador == 0)
    {
        cout << "| Sin Socios asignados..." << endl;
    }


}

void ServicioSocio::verSocios()
{
    int cantReg = _archivoSocio.cantidadRegistrosSocios();
    Socio socio;
    Socio* socios;
    int opc;
    do {
        cout << "Desea generar ademas un CSV? : " << endl;
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        cin >> opc;
        system("pause");
        system("cls");
    } while(opc < 1 || opc > 2);

    if (opc == 1){
        socios = new Socio[cantReg];
    }

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
        if(opc == 1){
            socios[i] = socio;
        }

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
    if(opc == 1){
        generarCSV(socios, cantReg);
        delete[] socios;
    }
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

void ServicioSocio::generarCSV(Socio socios[], int cantReg)
{


    FILE* archivo = fopen("sociosCSV.txt", "w");
    if (archivo == nullptr) {
        perror("Error al abrir el archivo");
        return;
    }

    Socio socio;
    fprintf(archivo, "Nombre,Apellido,DNI,ID Usuario,Fecha Nacimiento,Fecha Ingreso,Estado,ID Rol,ID Membresia,Estado Fisico,ID Rutina,ID Entrenador\n");

    for(int i=0; i < cantReg; i++){
        socio = socios[i];
        fprintf(archivo, "%s,%s,%d,%d,%s,%s,%d,%d,%d,%s,%d,%d\n",
            socio.getNombre().c_str(),
            socio.getApellido().c_str(),
            socio.getDni(),
            socio.getIdUsuario(),
            socio.getFechaNacimiento().toString().c_str(),
            socio.getFechaDeIngreso().toString().c_str(),
            socio.getEstado(),
            socio.getIdRol(),
            socio.getMembresia(),
            socio.getEstadoFisico(),
            socio.getIdRutina(),
            socio.getIdEntrenadorAsignado()
        );

    }
    fclose(archivo);
    cout << "sociosCSV.txt generado satisfactoriamente" << endl;
    system("pause");
    system("cls");
}

bool ServicioSocio::buscarSocioPorDni(int dni)
{

    int cantReg = _archivoSocio.cantidadRegistrosSocios();
    for(int i = 0; i < cantReg; i++)
    {
        if(_archivoSocio.leerRegistroSocio(i).getDni() == dni)
        {
            return true;
        }
    }
    return false;
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

    cout << "+--------------------------------------------------------------------------------+"<< endl;
    cout << "|     A continuacion lo guiaremos en el proceso para agregar un nuevo socio      |"<< endl;
    cout << "+--------------------------------------------------------------------------------+"<< endl;
    cout << "" << endl;

    cout << "Dni: ";
    cin >> dni;
    if(buscarSocioPorDni(dni))
    {
        cout << endl;
        cout << "El usuario con DNI " << dni << " ya existe en los registros" << endl;
        cout << endl;
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

    cout << endl;
    cout << "Ingrese fecha nacimiento: " << endl;
    fechaNacimiento = Fecha::crearFecha();

    cout << endl;
    cout << "Contrasenia: ";
    cin >> contrasenia;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Pin: ";
    cin >> pinIngreso;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    idMembresia = seleccionarMembresia();

    cout << endl;
    cout << "Estado fisico: ";
    cin >> estadoFisico;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    idRutina = 0;
    idEntrenadorAsignado = 0;

    cout << string(78, '-') << endl;

    Socio socio(nombre, apellido, dni, idUsuario, fechaNacimiento, fechaIngreso, contrasenia,
                estado, idRol, idMembresia, estadoFisico, idRutina, idEntrenadorAsignado, pinIngreso);

    if(_archivoSocio.guardarSocio(socio))
    {
        cout << "+----------------------------------+" << endl;
        cout << "|  Socio ingresado correctamente!  |" << endl;
        cout << "+----------------------------------+" << endl;
    }
    else
    {
        cout << "+---------------------------------------------+" << endl;
        cout << "|  Error inesperado, cuminiquese con soporte  |" << endl;
        cout << "+---------------------------------------------+" << endl;
    }



    system("pause");
}

void ServicioSocio::modificarSocio()
{
    system("cls");
    ServicioRutina rutina;
    ServicioEmpleado entrenador;

    int idSocio;
    int opc;

    cout << "+-----------------------------------------+" << endl;
    cout << "|             MODIFICAR SOCIO             |" << endl;
    cout << "+-----------------------------------------+" << endl;
    cout << endl;
    cout << " Ingrese ID: ";
    cin >> idSocio;

    int pos = _archivoSocio.buscarSocio(idSocio);

    if (pos == -1)
    {
        cout << endl;
        cout << " Socio con id #" << idSocio << " no encontrado." << endl;
        system("pause");
        return;
    }

    Socio soc = _archivoSocio.leerRegistroSocio(pos);

    do
    {
        system("cls");
        cout << "+-----------------------------------------+" << endl;
        cout << "|             MODIFICAR SOCIO             |" << endl;
        cout << "+-----------------------------------------+" << endl;
        cout << endl;
        cout << " A continuacion ingrese la opcion deseada: "<< endl;

        cout << string(43, '-') << endl;
        cout << "1. Modificar membresia" << endl;
        cout << "2. Cambiar rutina" << endl;
        cout << "3. Cambiar entrenador designado" << endl;
        cout << "4. Cambiar estado de un Socio" << endl;
        cout << "0. Volver/Guardar" << endl;
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
            if(soc.getIdEntrenadorAsignado() < 1000)
            {
                cout << endl;
                cout << "+------------------------------------------+" << endl;
                cout << "|  Primero se debe asignar un entrenador.  |" << endl;
                cout << "+------------------------------------------+" << endl;
            }
            else
            {
                int idRutina = rutina.elegirRutina(soc.getIdEntrenadorAsignado());
                soc.setIdRutina(idRutina);
            }

            break;
        }
        case 3:
        {
            int idEntrenador = entrenador.elegirEntrenador();
            soc.setIdEntrenadorAsignado(idEntrenador);
            break;
        }
        case 4:
        {
            if(soc.getEstado())
            {
                cout << " Esta seguro de cambiar el estado a Inhabilitado? (S/N): ";
            }
            else
            {
                cout << " Esta seguro de cambiar el estado a Habilitado? (S/N): ";
            }

            char confirmacion;
            cin >> confirmacion;
            if (confirmacion == 'S' || confirmacion == 's')
            {
                if(soc.getEstado())
                {
                    soc.setEstado(false);
                }
                else
                {
                    soc.setEstado(true);
                }
                cout << endl;
                cout << "Estado de usuario cambiado." << endl;
            }
            else
            {
                cout << endl;
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
        system("pause");
    }
    while (opc != 0);

    cout << " Confirmar Cambios? 1 - SI | 0 - NO" << endl;
    cout << " Su eleccion: ";
    cin >> opc;

    if(opc == 1 && _archivoSocio.guardarSocio(soc, pos))
    {
        cout << endl;
        cout << "Cambios guardado con exito" << endl;
    }

    system("pause");
}

void ServicioSocio::verEntrenadorAsignado(int idSocio)
{
    system("cls");
    string horarios;

    int pos = _archivoSocio.buscarSocio(idSocio);
    Socio socio = _archivoSocio.leerRegistroSocio(pos);


    pos = _archivoEmpleado.buscarEmpleado(socio.getIdEntrenadorAsignado());

    if (pos == -1)
    {
        cout << "+--------------------------------------------------------------------------------+"<< endl;
        cout << "| Aun no se le ha asignado un entrenador, en la brevedad se le estara asignando. |"<< endl;
        cout << "+--------------------------------------------------------------------------------+"<< endl;
        system("pause");
        return;
    }

    ServicioActividad sActividad;

    Empleado emp = _archivoEmpleado.leerRegistroEmpleado(pos);

    switch(emp.getIdTurno())
    {
    case 0:
        horarios = "08hs a 13hs";
        break;
    case 1:
        horarios = "13hs a 18hs";
        break;
    case 2:
        horarios = "18hs a 23hs";
        break;
    }

    cout << "+-----------------------------------------+" << endl;
    cout << "|           ENTRENADOR ASIGNADO           |" << endl;
    cout << "+-----------------------------------------+" << endl;
    cout << "-  Nombre: " << emp.getNombre() <<  endl;
    cout << "-  Apellido: " << emp.getApellido() << endl;
    cout << "- ";
    sActividad.buscarActividad(emp.getIdActividadPrincipal());
    cout << "-  Horario: " << horarios << endl;
    cout << "+-----------------------------------------+" << endl;


    system("pause");
}


Socio ServicioSocio::buscarSocioId(int idUsuario)
{

    int pos = _archivoSocio.buscarSocio(idUsuario);

    if (pos == -1)
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

    cout << "+----------------------------------+" << endl;
    cout << "| Tu membresia actual es: " << membresiaToStr(socio.getIdRol()) <<  "    |" << endl;
    cout << "+----------------------------------+" << endl;

    system("pause");
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
    int opc;
    do{
        cout << "Ingrese una opcion:" << endl;
        cout << string(78, '-') << endl;
        cout << "1. Ver lista socios" << endl;
        cout << "2. Guardar CSV" << endl;
        cout << string(78, '-') << endl;
        cin >> opc;
        system("cls");

    }while(opc < 0 || opc > 2);


    switch (opc){
        case 1:{
            listarSocios(socios, cantReg);
            break;
        }
        case 2: {
            generarCSV(socios, cantReg);
            break;
        }
    }


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
    int opc;
    do{
        cout << "Ingrese una opcion:" << endl;
        cout << string(78, '-') << endl;
        cout << "1. Ver lista socios" << endl;
        cout << "2. Guardar CSV" << endl;
        cout << string(78, '-') << endl;
        cin >> opc;
        system("cls");

    }while(opc < 0 || opc > 2);


    switch (opc){
        case 1:{
            listarSocios(socios, cantReg);
            break;
        }
        case 2: {
            generarCSV(socios, cantReg);
            break;
        }
    }

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

    cout << "Ingrese su nueva contrasenia: ";
    cin >> contra1;
    cout << "Repita nuevamente su contrasenia: ";
    cin >> contra2;

    contra1[sizeof(contra1)-1] = '\0';
    contra2[sizeof(contra2)-1] = '\0';

    if (strcmp(contra1, contra2)==0)
    {
        soc.setContrasenia(contra1);
        if (_archivoSocio.guardarSocio(soc, pos))
        {
            cout << "Contrasenia modificada y guardada correctamente." << endl;
        }
        else
        {
            cout << "Error al guardar los cambios. Contacte al administrador del sistema..." << endl;
        }
    }
    else
    {
        cout << "Contrasenias no coinciden, intente nuevamente ..." << endl;
    }
    system("pause");
}

void ServicioSocio::mostrarFechaVencimiento(Fecha fechaIngreso, int idSocio)
{
    Fecha fecha, fechaActual;
    ServicioPago pago;


    if(pago.verificarUltimoPago(idSocio))
    {
        fechaIngreso.setMes(fechaActual.getMes());
        fecha = fecha.sumarDiasParaVencimiento(fechaIngreso);

        cout << "+---------------------------------------------+" << endl;
        cout << "| Su proxima cuota vence el dia: " << fecha.toString() << "   |" << endl;
        cout << "+---------------------------------------------+" << endl;

    }
    else
    {
        /*cout << "+---------------------------------------------+" << endl;
        cout << "| Cuota vencida el dia: " << fechaIngreso.toString() << "           |" << endl;
        cout << "+---------------------------------------------+" << endl;*/

        cout << "+-----------------------------------------------------------+" << endl;
        cout << "| Cuota vencida, debe realizar el pago para activar su pase |" << endl;
        cout << "+-----------------------------------------------------------+" << endl;

    }

    system("pause");
    return;

    /*Fecha hoy = Fecha();
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

    */

}

void ServicioSocio::listarSocios(Socio socios[], int cantReg)
{
    Socio socio;

    cout << string(78, '-') << endl;
    cout << left << setw(6) << "ID" << "|"
         << setw(15) << "Apellido" << "|"
         << setw(15) << "Nombre" << "|"
         << setw(12) << "Fecha Ing." << "|"
         << setw(10) << "Membresia" << "|"
         << setw(14) << "DNI" << endl;
    cout << string(78, '-') << endl;

    for (int i = 0; i < cantReg; i++)
    {
        socio = socios[i];

        cout << left << setw(6) << socio.getIdUsuario() << "|"
             << setw(15) << socio.getApellido() << "|"
             << setw(15) << socio.getNombre() << "|"
             << setw(12) << socio.getFechaDeIngreso().toString() << "|"
             << setw(10) << membresiaToStr(socio.getMembresia()).c_str() << "|"
             << setw(14) << socio.getDni() << endl;
        if ((i+24)%25 == 0 && i != 1)
        {
            system("pause");
            system("cls");
        }
    }
    cout << string(78, '-') << endl;
    system("pause");
}

///--------------------------------------------------

bool ServicioSocio::consultarEstadoDeSocio(int idSocio)
{
    int pos = _archivoSocio.buscarSocio(idSocio);

    Socio socio = _archivoSocio.leerRegistroSocio(pos);

    ServicioPago pago;


    if(!pago.verificarUltimoPago(idSocio) && pago.cantidadDeDiasDelUltimoPago(idSocio) < 0)
    {
        socio.setEstado(false);

        _archivoSocio.guardarSocio(socio, pos);

        return false;

    }

    return true;

}

void ServicioSocio::actualizarEstadoDelSocio(int idSocio, bool estado)
{
    int pos = _archivoSocio.buscarSocio(idSocio);

    Socio socio = _archivoSocio.leerRegistroSocio(pos);

    socio.setEstado(estado);

    _archivoSocio.guardarSocio(socio, pos);
}

void ServicioSocio::buscarSocioPorId()
{
    system("cls");

    int idSocio;

    cout << "+----------------------------------------------------------------------------+" << endl;
    cout << "|                                  BUSCAR SOCIO                              |" << endl;
    cout << "+----------------------------------------------------------------------------+" << endl;
    cout << endl;
    cout << " Ingrese ID: ";
    cin >> idSocio;

    int pos = _archivoSocio.buscarSocio(idSocio);

    if (pos == -1)
    {
        cout << "Socio con ID #" << idSocio << " no encontrado..." << endl;
        system("pause");
        return;
    }
    Socio socio = _archivoSocio.leerRegistroSocio(pos);

    cout << string(78, '-') << endl;
    cout << left << setw(6) << "ID" << "|"
         << setw(15) << "Apellido" << "|"
         << setw(15) << "Nombre" << "|"
         << setw(12) << "Fecha Ing." << "|"
         << setw(10) << "Membresia" << "|"
         << setw(14) << "Estado" << endl;
    cout << string(78, '-') << endl;

    cout << left << setw(6) << socio.getIdUsuario() << "|"
         << setw(15) << socio.getApellido() << "|"
         << setw(15) << socio.getNombre() << "|"
         << setw(12) << socio.getFechaDeIngreso().toString() << "|"
         << setw(10) << membresiaToStr(socio.getMembresia()).c_str() << "|"
         << setw(14) << (socio.getEstado() ? "Habilitado" : "Deshabilitado") << endl;
    cout << string(78, '-') << endl;

    system("pause");
}

void ServicioSocio::verListaDeSociosSinEntrenador()
{
    int cantReg = _archivoSocio.cantidadRegistrosSocios();
    Socio socio;

    cout << "+-------------------------------------------------------------+" << endl;
    cout << "|                     SOCIOS SIN ENTRENADOR                   |" << endl;
    cout << "+-------------------------------------------------------------+" << endl;

    cout << string(63, '-') << endl;
    cout << left << setw(6) << "ID" << "|"
         << setw(15) << "Apellido" << "|"
         << setw(15) << "Nombre" << "|"
         << setw(12) << "Fecha Ing." << "|"
         << setw(10) << "Membresia" << "|" << endl;
    cout << string(63, '-') << endl;

    for (int i = 0; i < cantReg; i++)
    {
        socio = _archivoSocio.leerRegistroSocio(i);

        if(socio.getIdEntrenadorAsignado() < 1000 && socio.getEstado() == true)
        {
            cout << left << setw(6) << socio.getIdUsuario() << "|"
                 << setw(15) << socio.getApellido() << "|"
                 << setw(15) << socio.getNombre() << "|"
                 << setw(12) << socio.getFechaDeIngreso().toString() << "|"
                 << setw(10) << membresiaToStr(socio.getMembresia()).c_str() << "|" << endl;
        }

        if ((i+24)%25 == 0 && i != 1)
        {
            system("pause");
            system("cls");

        }
    }
    cout << string(63, '-') << endl;
    system("pause");
}

void ServicioSocio::verListaDeSociosSinRutina(int idEntrenador)
{
    int cantReg = _archivoSocio.cantidadRegistrosSocios();
    Socio socio;

    cout << "+-------------------------------------------------------------+" << endl;
    cout << "|                       SOCIOS SIN RUTINA                     |" << endl;
    cout << "+-------------------------------------------------------------+" << endl;

    cout << string(63, '-') << endl;
    cout << left << setw(6) << "ID" << "|"
         << setw(15) << "Apellido" << "|"
         << setw(15) << "Nombre" << "|"
         << setw(12) << "Fecha Ing." << "|"
         << setw(10) << "Membresia" << "|" << endl;
    cout << string(63, '-') << endl;

    for (int i = 0; i < cantReg; i++)
    {
        socio = _archivoSocio.leerRegistroSocio(i);

        if(socio.getIdRutina() == 0 && socio.getEstado() == true && socio.getIdEntrenadorAsignado() == idEntrenador)
        {
            cout << left << setw(6) << socio.getIdUsuario() << "|"
                 << setw(15) << socio.getApellido() << "|"
                 << setw(15) << socio.getNombre() << "|"
                 << setw(12) << socio.getFechaDeIngreso().toString() << "|"
                 << setw(10) << membresiaToStr(socio.getMembresia()).c_str() << "|" << endl;
        }

        if ((i+24)%25 == 0 && i != 1)
        {
            system("pause");
        }
    }
    cout << string(63, '-') << endl;
    system("pause");
}

void ServicioSocio::asignarUnaRutina(int idEntrenador)
{
    int cantReg = _archivoSocio.cantidadRegistrosSocios();
    Socio socio;
    ServicioRutina rutina;
    int idSocio, opcion;

    system("cls");
    cout << "+-------------------------------------------------------------+" << endl;
    cout << "|                      ASIGNAR UNA RUTINA                     |" << endl;
    cout << "+-------------------------------------------------------------+" << endl;
    cout << endl;
    cout << " Ingrese ID del Socio: ";
    cin >> idSocio;

    int pos = _archivoSocio.buscarSocio(idSocio);

    if(pos != -1)
    {
        socio = _archivoSocio.leerRegistroSocio(pos);

        if(socio.getIdEntrenadorAsignado() == idEntrenador)
        {
            int idRutina = rutina.elegirRutina(idEntrenador);

            system("cls");
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|                      ASIGNAR UNA RUTINA                     |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            cout << endl;
            cout << " ID Socio: " << socio.getIdUsuario() << endl;
            cout << " ID Rutina Seleccionada: " << idRutina << endl;
            cout << endl;
            cout << " Confirmar cambios? 1 - SI | 2 - NO " << endl;
            cout << " Su eleccion: ";
            cin >> opcion;

            if(opcion == 1)
            {
                socio.setIdRutina(idRutina);
                if( _archivoSocio.guardarSocio(socio, pos))
                {
                    cout << "+--------------------------------+" << endl;
                    cout << "|  Cambios guardados con exito.  |" << endl;
                    cout << "+--------------------------------+" << endl;
                }
            }

        }
        else
        {
            cout << "+---------------------------------------------------------+" << endl;
            cout << "| Error. El Socio se encuentra asignado a otro entrenado. |" << endl;
            cout << "+---------------------------------------------------------+" << endl;
        }
    }
    else
    {

        cout << "+-----------------------+" << endl;
        cout << "|  ID No encontrado...  |" << endl;
        cout << "+-----------------------+" << endl;
    }

    cout << endl;
    system("pause");
}

