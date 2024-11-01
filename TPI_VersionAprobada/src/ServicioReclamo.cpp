#include <iostream>
#include "ServicioReclamo.h"
#include "Reclamo.h"
#include "Fecha.h"
#include "ServicioSocio.h"

using namespace std;

ServicioReclamo::ServicioReclamo() {

    _archivoReclamos = GestionArchivoReclamos("GestionArchivoReclamos.dat");
}

void ServicioReclamo::cargarReclamo(int idUsuario) {

    system("cls");
    ServicioSocio ss;
	bool resuelto;
	Fecha fechaActual;
	std::string detalle;

    idReclamo = obtenerUltimoIdReclamo();

    std::cout << "              ||| NUEVO RECLAMO |||               " << std::endl;
    std::cout << " -- Por favor ingrese su reclamo -- " << std::endl;
    std::cin >> detalle;
    cin.ignore();
    getline(cin, detalles);

	//fecha.setFechaActual();

    Reclamo reclamo(idReclamo, idUsuario, false, detalles, fechaActual);

    if(_archivoReclamos.guardarReclamo(reclamo))
    {
        cout << " --- Reclamo realizado con exito, ID #" << idReclamo << " --- " << endl;
        cout << " Fecha: " << fechaActual.toString() << endl;
    }
    else
    {
        std::cout << " --- No se pudo guardar su reclamo, intentelo mas tarde. --- ";
    }

    system("pause");
}

void ServicioReclamo::mostrarReclamo(bool resuelto) {

    system("cls");
    Reclamo r;

    int cantidad = _archivoReclamos.getCantidadReclamos();

    if(cantidad > 0)
    {
        for(int i=0; i<cantidad; i++)
        {
            reclamo = _archivoReclamos.leerReclamo(i);

            if(reclamo.getEstaResuelto() == resuelto)
            {
                cout << "-----------------------------------------" << endl;
                cout << " ID Reclamo #" << r.getIdReclamo() << endl;
                cout << " ID Usuario #" << r.getIdUsuario() << endl;
                cout << " Fecha: " << r.getFecha().toString() << endl;
                cout << " Detalle: " << r.getDetalle() << endl;
            }
        }
    }
    else
    {
        cout << " --- No existen reclamos --- " << endl;
    }

    cout << endl;
    system("pause");
}

void ServicioReclamo::verReclamosUsuario(int idUsuario){

	int idUsuario;
	Reclamo r;

	int cantReclamos = _archivoReclamos.getCantidadReclamos();
	int tam = _archivoReclamos.cantidadDeRegistrosPorUsuario(cantReclamos, idUsuario);

	Reclamo *vReclamos;
	vReclamos = new Reclamo[tam];

	*vReclamos = _archivoReclamos.leerRegistrosPorUsuario(cantReclamos, vReclamos, tam, idUsuario);

	 for(int i = 0; i < tam; i++)
    {
        reclamo = _archivoReclamos.leerRegistrosReclamo(vReclamos[i]);

        cout << "-------------------------------------------" << endl;
        if(reclamo.getEstaResuelto())
        {
            cout << " Estado del reclamo: RESUELTO" << endl;
        }
        else
        {
            cout << " Estado del reclamo: ACTIVO" << endl;
        }
        cout << " ID #" << reclamo.getIdReclamo() << endl;
        cout << " Detalle: " << reclamo.getDetalle() << endl;
    }

    system("pause");

	delete[] vReclamos;
}

void ServicioReclamo::cambiarEstadoReclamo() {

    system("cls");
    int idReclamo, opcion;
    Reclamo reclamo;

    cout << " Ingrese ID de Reclamo: ";
    cin >> idReclamo;

    int pos = _archivoReclamos.buscarReclamo(idReclamo);

    if(pos != -1)
    {
        reclamo = _archivoReclamos.leerReclamo(pos);

        if(reclamo.getEstaResuelto())
        {
            cout << " Estado: RESUELTO" << endl;
            cout << endl;
            cout << " Desea cambiar el estado a ACTIVO: 1-SI | 2-NO" << endl;
            cin >> opcion;
            if(opcion)
            {
                reclamo.setEstaResuelto(false);
                _archivoReclamos.modificarReclamo(reclamo, pos);
            }
        }
        else
        {
            cout << " Estado: ACTIVO" << endl;
            cout << endl;
            cout << " Desea cambiar el estado a RESUELTO: 1-SI | 2-NO" << endl;
            cin >> opcion;
            if(opcion)
            {
                reclamo.setEstaResuelto(true);
                _archivoReclamos.modificarReclamo(reclamo, pos);
            }
        }
    }
    else
    {
        cout << " --- El ID no existe --- " << endl;
    }

    cout << endl;
    system("pause");
}

int ServicioReclamo::obtenerUltimoIdReclamo()
{
    int cantidad = _archivoReclamos.cantidadRegistrosReclamos();

    if(cantidad != -1)
    {
        return cantidad+1;
    }
    else
    {
        return 1;
    }
}
