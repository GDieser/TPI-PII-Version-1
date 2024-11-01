#include <iostream>

#include "ServicioRutina.h"
#include "Rutina.h"

using namespace std;


ServicioRutina::ServicioRutina()
{
    _archivoRutina = GestionArchivoRutinas("archivoRutinas.dat");
    _archivoDetallesRutina = GestionArchivoDetalleRutinas("archivoDetalleRutinas.dat");
}

void ServicioRutina::verRutinas(int idEntrenador)
{
    system("cls");
    int *vectPos;
    int indice = 1;
    Rutina rutina;

    int cantidad = _archivoRutina.cantidadRegistrosRutinas();
    if(cantidad != -1)
    {
        int tam =  _archivoRutina.cantidadDeRegistrosPorEntrenador(cantidad, idEntrenador);
        vectPos = new int[tam];
        if(vectPos == nullptr)
        {
            return;
        }

        *vectPos = _archivoRutina.leerRegistrosRutinasPorEntrenador(cantidad, vectPos, tam, idEntrenador);

        cout << "+------------------------------------------+" << endl;
        cout << "|                MIS RUTINAS               |" << endl;
        cout << "+------------------------------------------+" << endl;
        cout << endl;

        for(int i=0; i<tam; i++)
        {
            rutina = _archivoRutina.leerRegistroRutina(vectPos[i]);

            cout << " " << indice << ".  Nombre             : " << rutina.getNombreRutina() << endl;
            cout << "     ID                 : #" << rutina.getIdRutina() << endl;
            cout << "     Descripcion        : " << rutina.getDescripcion() << endl;
            cout << "     Frecuencia Semanal : " << rutina.getFrecuenciaSemanal()<< endl;
            cout << "+------------------------------------------+" << endl;
            indice++;
        }

        cout << endl;
        delete []vectPos;
    }
    else
    {
        cout << " Sin registros disponibles." << endl;
    }

    system("pause");
}

void ServicioRutina::verDetallesDeRutina()
{
    system("cls");
    int idRutina;

    DetalleRutina detalle;

    cout << "+--------------------------------------+" << endl;
    cout << "|          DETALLES DE RUTINA          |" << endl;
    cout << "+--------------------------------------+" << endl;
    cout << endl;

    cout << " Ingrese ID de Rutina: #";
    cin >> idRutina;
    cout << endl;

    int pos = _archivoDetallesRutina.buscarDetalleRutina(idRutina);

    if(pos != -1)
    {
        detalle = _archivoDetallesRutina.leerRegistroDetalleRutina(pos);

        int *idEjercicios = detalle.getIdEjercicios();
        int *repeticiones = detalle.getRepeticiones();
        float *peso = detalle.getPeso();

        for(int i=0; i<10; i++)
        {
            if(idEjercicios[i] != 0)
            {
                cout << " ID Ejercicio : #" << idEjercicios[i] << endl;
                cout << " Repeticiones : " << repeticiones[i] << endl;
            }
            if(peso[i] != 0)
            {
                cout << " Peso         : " << peso[i] << endl;
            }
        }
    }
    else
    {
        cout << "No se encontraron registros con es ID" << endl;
    }

    system("pause");
}

void ServicioRutina::crearRutina(int idEntrenador)
{
    system("cls");
    string nombre, descripcion;
    int frecuencia, idRutina;

    DetalleRutina detalle;

    cout << "+----------------------------------------------+" << endl;
    cout << "|              CREAR NUEVA RUTINA              |" << endl;
    cout << "+----------------------------------------------+" << endl;
    cout << endl;

    cout << " Nombre de la rutina      : ";
    cin.ignore();
    getline(cin, nombre);
    cout <<  " Descripcion de la rutina : ";
    getline(cin, descripcion);
    cout << " Frecuencia semanal       : ";
    cin >> frecuencia;

    idRutina = obtenerUltimoIdRutina();

    Rutina rutina(idRutina, frecuencia, idEntrenador, nombre, descripcion);

    if(_archivoRutina.guardarRutina(rutina))
    {
        system("cls");
        cout << "+----------------------------------------------+" << endl;
        cout << "|              CREAR NUEVA RUTINA              |" << endl;
        cout << "+----------------------------------------------+" << endl;
        cout << endl;
        cout << " Rutina agregada exitosamente, ID #" << idRutina <<endl;
        cout << endl;
        cout << " Inicio de carga de detalles de la rutina..." << endl;
        cout << endl;
        system("pause");

        detalle = crearDetalleRutina(idRutina);

        if(_archivoDetallesRutina.guardarDetalleRutina(detalle))
        {
            cout << endl;
            cout << " Detalles agregados exitosamente" << endl;
        }
        else
        {
            cout << endl;
            cout << "Error de registro..." << endl;
        }

    }
    else
    {
        cout << "Error de registro..." << endl;
    }

    system("pause");
}

DetalleRutina ServicioRutina::crearDetalleRutina(int idRutina)
{
    int opcion = 1, contador = 0;
    int idEjercicio[10]= {}, repeticiones[10]= {};
    float peso[10]= {};

    while(contador < 10 && opcion != 0)
    {
        system("cls");

        cout << "+----------------------------------------------+" << endl;
        cout << "|              DETALLES DE RUTINA              |" << endl;
        cout << "+----------------------------------------------+" << endl;
        cout << endl;
        cout << " - Ejercicios cargados     : " << contador << endl;
        cout << endl;
        cout << " - Ingrese ID de Ejercicio : ";
        cin >> idEjercicio[contador];
        cout << " - Repeticiones            : ";
        cin >> repeticiones[contador];
        cout << " - Peso (0 si no aplica)   : ";
        cin >> peso[contador];
        cout << endl;
        cout << " Agregar otro ejercicio a la rutina? (Maximo 10) " << endl;
        cout << "                    1-SI | 0-NO " << endl;
        cout << endl;
        cout << " Su eleccion: ";
        cin >> opcion;

        contador++;
    }



    return DetalleRutina(idEjercicio, idRutina, repeticiones, peso);
}

void ServicioRutina::mostrarRutinasPorEntrenador(int idEntrenador)
{
    system("cls");
    Rutina rutina;
    int indice = 1;

    int cantidad = _archivoRutina.cantidadRegistrosRutinas();

    cout << "+----------------------------------------------+" << endl;
    cout << "|              RUTINAS DISPONIBLES             |" << endl;
    cout << "+----------------------------------------------+" << endl;
    cout << endl;

    for(int i=0; i<cantidad; i++)
    {
        rutina = _archivoRutina.leerRegistroRutina(i);
        if(rutina.getIdEntrenador() == idEntrenador)
        {
            cout << " -" << indice << ". Nombre             : " << rutina.getNombreRutina() << endl;
            cout << "     ID                 : #" << rutina.getIdRutina() << endl;
            cout << "     Descripcion        : " << rutina.getDescripcion() << endl;
            cout << "     Frecuencia Semanal : " << rutina.getFrecuenciaSemanal()<< endl;
            cout << "+----------------------------------------------+" << endl;
            indice++;
        }
    }
    system("pause");
}

///Que arranque en 1 y sea autonumerico
int ServicioRutina::obtenerUltimoIdRutina()
{
    int cantidad = _archivoRutina.cantidadRegistrosRutinas();

    if(cantidad != -1)
    {
        return cantidad+1;
    }
    else
    {
        return 1;
    }
}

void ServicioRutina::verRutinaAsignada(int idRutina)
{
    system("cls");
    Rutina rutina;

    int pos = _archivoRutina.buscarRutina(idRutina);
    rutina = _archivoRutina.leerRegistroRutina(pos);


    cout << "+--------------------------------------------+" << endl;
    cout << "|               RUTINA ASIGNADA              |" << endl;
    cout << "+--------------------------------------------+" << endl;
    cout << endl;

    if(pos != -1)
    {
        rutina = _archivoRutina.leerRegistroRutina(pos);

        cout << " Nombre             : " << rutina.getNombreRutina() << endl;
        cout << " ID                 : #" << rutina.getIdRutina() << endl;
        cout << " Descripcion        : " << rutina.getDescripcion() << endl;
        cout << " Frecuencia Semanal : " << rutina.getFrecuenciaSemanal()<< endl;
        cout << "+--------------------------------------------+" << endl;
    }
    else
    {
        cout << " Rutina no asignada, comuniquese con su entrenador..." << endl;
    }

    system("pause");
}

void ServicioRutina::buscarRutina()
{
    int idRutina;
    Rutina rutina;

    system("cls");
    cout << "+------------------------------------------+" << endl;
    cout << "|               BUSCAR RUTINA              |" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << endl;
    cout << " Ingrese ID de rutina: ";
    cin >> idRutina;

    int pos = _archivoRutina.buscarRutina(idRutina);

    if(pos != -1)
    {
        rutina = _archivoRutina.leerRegistroRutina(pos);

        system("cls");
        cout << "+------------------------------------------+" << endl;
        cout << "|               BUSCAR RUTINA              |" << endl;
        cout << "+------------------------------------------+" << endl;
        cout << endl;

        cout << " Nombre             : " << rutina.getNombreRutina() << endl;
        cout << " ID                 : #" << rutina.getIdRutina() << endl;
        cout << " Descripcion        : " << rutina.getDescripcion() << endl;
        cout << " Frecuencia Semanal : " << rutina.getFrecuenciaSemanal()<< endl;
        cout << "+------------------------------------------+" << endl;
    }
    else
    {
        cout << endl;
        cout << " ID no econtrado" << endl;
    }

    system("pause");
}

int ServicioRutina::elegirRutina(int idEntrenador)
{
    system("cls");
    int indice = 1, opcion;
    int *vectRutinas;
    Rutina rutina;

    int cantidad = _archivoRutina.cantidadRegistrosRutinas();

    if(cantidad == -1)
    {
        cout << "No se encunetran registros de Rutina, comuniquese con soporte" << endl;

        system("pause");
        return -1;
    }

    int cantRutina = _archivoRutina.cantidadDeRegistrosPorEntrenador(cantidad, idEntrenador);

    vectRutinas = new int[cantRutina];
    if(vectRutinas == nullptr)
    {
        cout << "Error inesperado, comuniquese con soporte" << endl;

        system("pause");
        return -1;
    }

    *vectRutinas = _archivoRutina.leerRegistrosRutinasPorEntrenador(cantidad, vectRutinas, cantRutina, idEntrenador);

    cout << "+--------------------------------------+" << endl;
    cout << "|            ELEGIR RUTINA             |" << endl;
    cout << "+--------------------------------------+" << endl;
    cout << endl;

    for(int i=0; i<cantRutina; i++)
    {
        rutina = _archivoRutina.leerRegistroRutina(vectRutinas[i]);

        cout << " -" << indice << ". Nombre             : " << rutina.getNombreRutina() << endl;
        cout << "     Descripcion        : " << rutina.getDescripcion() << endl;
        cout << "     Frecuencia Semanal : " << rutina.getFrecuenciaSemanal()<< endl;
        cout << "+--------------------------------------+" << endl;
        indice++;
    }

    cout << endl;
    cout << " Seleccione su rutina (1 a " << cantRutina << "): ";
    cin >> opcion;

    rutina = _archivoRutina.leerRegistroRutina(vectRutinas[opcion-1]);

    int idRutina = rutina.getIdRutina();

    delete []vectRutinas;

    system("pause");

    return idRutina;
}

void ServicioRutina::asignarRutina()
{
    system("cls");


    system("pause");
}

void ServicioRutina::modificarRutina(int idEntrenador)
{
    system("cls");


    system("pause");
}
