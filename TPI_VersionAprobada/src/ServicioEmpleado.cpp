#include <iostream>
#include <cstring>

#include "ServicioEmpleado.h"
#include "ServicioSocio.h"
#include "ServicioActividad.h"

using namespace std;


ServicioEmpleado::ServicioEmpleado()
{
    _archivoEmpleado = GestionArchivoEmpleados("archivoEmpleados.dat");
}

void ServicioEmpleado::verEmpleados(int idRol)
{
    system("cls");
    Empleado empleado;
    ServicioActividad actividad;

    int cantidad = _archivoEmpleado.cantidadRegistrosEmpleados();

    for(int i=0; i<cantidad; i++)
    {
        empleado = _archivoEmpleado.leerRegistroEmpleado(i);

        if(empleado.getIdRol() == idRol && empleado.getEstado())
        {
            cout << "---------------------------" << endl;
            cout << " Nombre: " << empleado.getNombre() << endl;
            cout << " Apellido: " << empleado.getApellido() << endl;
            cout << " Fecha de ingreso: " << empleado.getFechaDeIngreso().toString() << endl;
            cout << " Legajo: " << empleado.getLegajo() << endl;
            if(empleado.getIdActividadPrincipal() == 0)
            {
                cout << " Actividad: Gerente" << endl;
            }
            else
            {
                actividad.buscarActividad(empleado.getIdActividadPrincipal());
            }

        }
    }

    system("pause");
}


void ServicioEmpleado::agregarEmpleado(int idRol)
{
    string nombre, apellido, pass1, pass2;
    int dni, idUsuario, opcion;
    int dia, mes, anio;
    Fecha fechaIngreso;
    bool estado = true;
    int legajo, idTurno, idActividadPrincipal = 0;
    bool semana[7] = {};

    ServicioActividad actividad;
    ServicioEmpleado servicio;

    system("cls");
    cout << "+----------------------------+" << endl;
    cout << "|  INGRESO DATOS PERSONALES: |" << endl;
    cout << "+----------------------------+" << endl;
    cout << endl;
    cout << " DNI: ";
    cin >> dni;

    if(servicio.comprobarDniEmpleado(dni) != -1)
    {
        cout << " DNI ya ingresado, ID #" << servicio.comprobarDniEmpleado(dni) << endl;
        cout << " Compruebe su estado en apartado <BUSCAR> " << endl;
        system("pause");
        return;
    }
    cout << " Nombre: ";
    cin >> nombre;
    cout << " Apellido: ";
    cin >> apellido;

    system("cls");
    cout << "+-----------------------+" << endl;
    cout << "|  FECHA DE NACIMIENTO: |" << endl;
    cout << "+-----------------------+" << endl;
    cout << endl;
    cout << " Dia: ";
    cin >> dia;
    cout << " Mes: ";
    cin >> mes;
    cout << " Anio: ";
    cin >> anio;

    system("cls");
    cout << "+-------------------------+" << endl;
    cout << "|      TURNO LABORAL:     |" << endl;
    cout << "+-------------------------+" << endl;
    cout << endl;
    cout << " 0 - 8hs a 13hs " << endl;
    cout << " 1 - 13hs a 18hs " << endl;
    cout << " 2 - 18hs a 23hs " << endl;
    cout << endl;
    cout << " Su Selecion: ";
    cin >> idTurno;

    do
    {
        system("cls");
        cout << "+-----------------------+" << endl;
        cout << "|      CONTRASENIA:     |" << endl;
        cout << "+-----------------------+" << endl;
        cout << endl;
        cout << " Ingrese contrasenia: ";
        cin >> pass1;
        cout << " Repita contrasenia: ";
        cin >> pass2;

        if( strcmp(pass1.c_str(), pass2.c_str()) != 0)
        {
            cout << " Contrasenias no coinciden, vuelva a intentar." << endl;
            system("pause");
        }

    }
    while(strcmp(pass1.c_str(), pass2.c_str()) != 0);


    if(idRol == 1)
    {
        system("cls");
        cout << "+---------------------+" << endl;
        cout << "|      ACTIVIDAD:     |" << endl;
        cout << "+---------------------+" << endl;
        cout << endl;
        cout << " 1 - Ver Actividades disponibles " << endl;
        cout << " 2 - Agregar nueva Actividad " << endl;
        cout << endl;
        cout << " Su seleccion: ";
        cin >> opcion;
        if(opcion == 1)
        {
            actividad.listarActividades();
            cout << endl;
            cout << " Ingrese ID Actividad principal: ";
            cin >> idActividadPrincipal;
        }
        else
        {
            idActividadPrincipal = actividad.agregarActividad();
        }
    }

    Fecha fechaNacimiento(dia, mes, anio);
    idUsuario = servicio.obternerUltimoId();
    legajo = servicio.obternerUltimoLegajo();

    Empleado empleado(nombre, apellido, dni, idUsuario, fechaNacimiento, fechaIngreso, pass1, estado, idRol, legajo, idTurno, idActividadPrincipal, semana);


    system("cls");
    if(_archivoEmpleado.guardarEmpleado(empleado))
    {
        cout << " Nombre: " << nombre << ", apellido: " << apellido << endl;
        cout << " Fecha de nacimiento: " << fechaNacimiento.toString() << endl;
        cout << " ID# " << idUsuario << ", legajo " << legajo << " agregado exitosamente." << endl;
    }
    else
    {
        cout << "Error de ingreso" << endl;
    }

    system("pause");

}

void ServicioEmpleado::restaurarUnEmpleado(int idRol)
{
    int idEmpleado;
    bool opcion;
    Empleado empleado;

    system("cls");
    cout << "Ingrese ID     : #";
    cin >> idEmpleado;

    int pos = _archivoEmpleado.buscarEmpleado(idEmpleado);

    if(pos != -1)
    {
        empleado = _archivoEmpleado.leerRegistroEmpleado(pos);

        if(empleado.getIdRol() == idRol)
        {
            if(!empleado.getEstado())
            {
                cout << " Nombre        : " << empleado.getNombre() << endl;
                cout << " Apellido      : " << empleado.getApellido() << endl;
                cout << " DNI           : " << empleado.getDni() << endl;
                cout << " Fecha Ingreso : " << empleado.getFechaDeIngreso().toString() << endl;
                cout << endl;
                cout << " Desea volver a activar al empleado? 1 - SI | 0 - NO " << endl;
                cout << " Su seleccion: ";
                cin >> opcion;

                empleado.setEstado(opcion);

                if(_archivoEmpleado.guardarEmpleado(empleado, pos))
                {
                    system("cls");
                    cout << " ID # " << idEmpleado << endl;
                    cout << " Estado Actualizado a ACTIVO " << endl;
                }
            }
            else
            {
                cout << " El estado es ACTIVO." << endl;
            }
        }
        else
        {
            system("cls");
            if(idRol == 0)
            {
                cout << " ID corresponde a un Entrenador, dirijase al gestor correspondiente...." << endl;
            }
            else
            {
                cout << " ID corresponde a un Gerente, dirijase al gestor correspondiente...." << endl;
            }
        }
    }
    system("pause");

}


void ServicioEmpleado::modificarEmpleado(int idRol)
{

}

void ServicioEmpleado::asignarHorarios()
{
    Empleado empleado;
    int idUsuario, opcion;
    bool diaSemana[7] = {}, agregar;
    string horarios;


    system("cls");
    cout << " Ingrese ID del entrenador: ";
    cin >> idUsuario;

    int pos = _archivoEmpleado.buscarEmpleado(idUsuario);

    if(pos != -1)
    {
        empleado = _archivoEmpleado.leerRegistroEmpleado(pos);
    }
    else
    {
        cout << " ID incorrecto..." << endl;
        system("pause");
        return;
    }

    switch(empleado.getIdTurno())
    {
    case 0:
        horarios = "8hs a 13hs";
        break;
    case 1:
        horarios = "13hs a 18hs";
        break;
    case 2:
        horarios = "18hs a 23hs";
        break;
    }

    system("cls");
    cout << "+----------------------+" << endl;
    cout << "|   ASIGNAR HORARIOS   |" << endl;
    cout << "+----------------------+" << endl;

    for(int i=0; i<7; i++)
    {
        if(!diaSemana[i])
        {
            switch(i)
            {
            case 0:
                cout << " Lunes de " << horarios << endl;
                break;
            case 1:
                cout << " Martes de " << horarios << endl;
                break;
            case 2:
                cout << " Miercoles de " << horarios << endl;
                break;
            case 3:
                cout << " Jueves de " << horarios << endl;
                break;
            case 4:
                cout << " Viernes de " << horarios << endl;
                break;
            case 5:
                cout << " Sabado de " << horarios << endl;
                break;
            case 6:
                cout << " Domingo de " << horarios << endl;
                break;
            }

            cout << " Agregar? 1 - SI || 0 - NO: ";
            cin >> agregar;
            cout << "+-------------------------------+" << endl;
            diaSemana[i] = agregar;
        }
    }

    cout << endl;
    cout << " Confirmar Asignacion 1 - SI | 0 - NO: ";
    cin >> opcion;

    if(opcion == 1)
    {
        empleado.setDiaSem(diaSemana);
        if(_archivoEmpleado.guardarEmpleado(empleado, pos))
        {
            system("cls");
            cout << "Cambios realizados con exito" << endl;
        }
    }

    system("pause");

}

void ServicioEmpleado::verHorariosAsignados(int idUsuario)
{
    Empleado empleado;
    bool *diaSemana;
    string horarios;

    int pos = _archivoEmpleado.buscarEmpleado(idUsuario);

    if(pos != -1)
    {
        empleado = _archivoEmpleado.leerRegistroEmpleado(pos);

        switch(empleado.getIdTurno())
        {
        case 0:
            horarios = "8hs a 13hs";
            break;
        case 1:
            horarios = "13hs a 18hs";
            break;
        case 2:
            horarios = "18hs a 23hs";
            break;
        }

        system("cls");
        cout << "+-------------------------------+" << endl;
        cout << "|     HORARIOS DE LA SEMANA     |" << endl;
        cout << "+-------------------------------+" << endl;
        for(int i=0; i<7; i++)
        {
            diaSemana = empleado.getDiaSem();
            if(diaSemana[i])
            {
                switch(i)
                {
                case 0:
                    cout << " Lunes     : " << horarios << endl;
                    break;
                case 1:
                    cout << " Martes    : " << horarios << endl;
                    break;
                case 2:
                    cout << " Miercoles : " << horarios << endl;
                    break;
                case 3:
                    cout << " Jueves    : " << horarios << endl;
                    break;
                case 4:
                    cout << " Viernes   : " << horarios << endl;
                    break;
                case 5:
                    cout << " Sabado    : " << horarios << endl;
                    break;
                case 6:
                    cout << " Domingo   : " << horarios << endl;
                    break;
                }
                cout << "+-------------------------------+" << endl;

            }
        }
    }
    system("pause");

}

int ServicioEmpleado::obternerUltimoIdEmpleado()
{
    Empleado empleado;

    int cantidad = _archivoEmpleado.cantidadRegistrosEmpleados();

    if(cantidad > 0)
    {
        empleado = _archivoEmpleado.leerRegistroEmpleado(cantidad - 1);
        return empleado.getIdUsuario();
    }

    return -1;
}

int ServicioEmpleado::obternerUltimoId()
{
    ServicioSocio socio;

    if(socio.obternerUltimoIdSocio() > obternerUltimoIdEmpleado())
    {
        return socio.obternerUltimoIdSocio()+1;
    }
    else
    {
        return obternerUltimoIdEmpleado()+1;
    }
}

int ServicioEmpleado::obternerUltimoLegajo()
{
    Empleado empleado;

    int cantidad = _archivoEmpleado.cantidadRegistrosEmpleados();

    if(cantidad > 0)
    {
        empleado = _archivoEmpleado.leerRegistroEmpleado(cantidad - 1);
        return empleado.getLegajo()+1;
    }

    return -1;
}


void ServicioEmpleado::modificarContrasenia(int idEmpleado)
{
    system("cls");
    string pass, pass2;
    Empleado empleado;


    int posicion = _archivoEmpleado.buscarEmpleado(idEmpleado);

    empleado = _archivoEmpleado.leerRegistroEmpleado(posicion);

    cout << " MODIFICAR CONTRASENIA" << endl;
    cout << "-----------------------------" << endl;
    cout << " Ingrese contrasenia actual: " << endl;
    cin >> pass;

    if(!strcmp(empleado.getContrasenia().c_str(), pass.c_str()))
    {
        cout << " Ingrese la nueva contrasenia: " << endl;
        cin >> pass;
        cout << " Repita la nueva contrasenia: " << endl;
        cin >> pass2;
        if(!strcmp(pass.c_str(), pass2.c_str()))
        {
            empleado.setContrasenia(pass);
            _archivoEmpleado.guardarEmpleado(empleado, posicion);
        }
        else
        {
            cout << "Las contrasenias no coinciden" << endl;
            system("pause");
            return;
        }
    }
    else
    {
        cout << "Contrasenia incorrecta" << endl;
        system("pause");
        return;
    }

}

void ServicioEmpleado::buscarUnEmpleado(int idRol)
{
    int idUsuario;
    Empleado empleado;
    ServicioActividad actividad;

    system("cls");
    cout << " Ingrese ID: #";
    cin >> idUsuario;

    int pos = _archivoEmpleado.buscarEmpleado(idUsuario);

    if(pos != -1)
    {
        empleado = _archivoEmpleado.leerRegistroEmpleado(pos);

        if(empleado.getIdRol() == idRol)
        {
            cout << endl;
            cout << " Nombre          : " << empleado.getNombre() << endl;
            cout << " Apellido        : " << empleado.getApellido() << endl;
            cout << " Fecha Ingreso   : " << empleado.getFechaDeIngreso().toString() << endl;
            cout << " Legajo          : " << empleado.getLegajo() << endl;
            if(empleado.getIdRol() == 0)
            {
                cout << " Actividad       : Gerente" << endl;
            }
            else
            {
                actividad.buscarActividad(empleado.getIdActividadPrincipal());
            }

            cout << " Estado          : ";
            if(empleado.getEstado())
            {
                cout << " ACTIVO " << endl;
            }
            else
            {
                cout << " DADO DE BAJA " << endl;
            }
        }
        else
        {
            if(idRol == 0)
            {
                cout << " Id ingresado corresponde a un Entrenador..." << endl;
            }
            else
            {
                cout << " Id ingresado corresponde a un Gerente..." << endl;
            }
        }

    }
    else
    {
        cout << " ID no encontrado..." << endl;
    }

    system("pause");
}

int ServicioEmpleado::seleccionarEntrenador()
{
    int *vectPosiciones;
    int *vectorID;
    int opcion;
    Empleado entrenador;
    ServicioActividad actividad;

    int cantidad = _archivoEmpleado.cantidadRegistrosEmpleados();
    int cantEntrenadores = _archivoEmpleado.cantidadRegistrosEmpleadosPorEstado(cantidad, true, 1);

    vectPosiciones = new int[cantEntrenadores];
    vectorID = new int[cantEntrenadores];

    if(vectPosiciones == nullptr || vectorID == nullptr)
    {
        return -1;
    }

    *vectPosiciones = _archivoEmpleado.leerRegistrosEmpleadosActivos(cantidad, vectPosiciones, cantEntrenadores, 1);

    for(int i=0; i<cantEntrenadores; i++)
    {
        entrenador = _archivoEmpleado.leerRegistroEmpleado(vectPosiciones[i]);

        cout << "--------------------" << endl;
        cout << " ENTRENADOR: " << i+1 << endl;
        cout << "--------------------" << endl;
        cout << " Nombre: " << entrenador.getNombre() << endl;
        cout << " Apellido: " << entrenador.getApellido() << endl;
        actividad.buscarActividad(entrenador.getIdActividadPrincipal());

        vectorID[i] = entrenador.getIdUsuario();
    }

    cout << endl;
    cout << " Seleccione un entrenador: (1 a " << cantEntrenadores << "): ";
    cin >> opcion;

    int idSeleccionado = vectorID[opcion-1];

    delete []vectPosiciones;
    delete []vectorID;

    return idSeleccionado;

    system("pause");
}

int ServicioEmpleado::comprobarDniEmpleado(int dni)
{
    int cantidad = _archivoEmpleado.cantidadRegistrosEmpleados();
    Empleado empleado;

    if(cantidad != -1)
    {
        for(int i=0; i<cantidad; i++)
        {
            empleado = _archivoEmpleado.leerRegistroEmpleado(i);
            if(empleado.getDni() == dni)
            {
                return empleado.getIdUsuario();
            }
        }
    }

    return -1;
}

void ServicioEmpleado::verSociosAsignados()
{

}
