#include <iostream>

#include "ServicioPago.h"
#include "RegistroPago.h"
#include "GestionArchivoPagos.h"
#include "ServicioPago.h"

using namespace std;

ServicioPago::ServicioPago()
{
    _archivoPago = GestionArchivoPagos("archivoPago.dat");
}

bool ServicioPago::verificarUltimoPago(int idSocio)
{

    system("cls");

    RegistroPago pago;
    Fecha fechaActual;

    int cantPagos = _archivoPago.getCantidadPagos();
    int pos = _archivoPago.ultimoPagoSocio(cantPagos, idSocio);

    if (pos != -1)  // chequeo si existe un pago
    {
        pago = _archivoPago.leerPago(pos);
        if (pago.getPeriodo().getMes() > fechaActual.getMes())
        {
            return true;
        }
        else if ((pago.getPeriodo().getDia() - fechaActual.getDia()) > 10)
        {
            return true;
        }
    }
    return false;

    system("pause");
}

void ServicioPago::registrarPago(int idSocio, int idMembresia, Fecha periodo)
{

    // validar si esta hecho el pago, con respecto a la ultima fecha de pago
    // consultar si desea mantener la membresia o no
    system("cls");

    Fecha fechaActual;
    float monto;

    if (verificarUltimoPago(idSocio))
    {
        cout << " --- Pago al dia. --- " << endl;
        return;
    }

    int mes = fechaActual.getMes();
    periodo.setMes(mes + 1); // al mes que traigo por parametro le sumo 1.

    switch (idMembresia)
    {
    case 0:
        monto = 55000;
        break;
    case 1:
        monto = 35000;
        break;
    case 2:
        monto = 25000;
        break;
    }

    RegistroPago pago(idSocio, monto, periodo, fechaActual);

    if (_archivoPago.guardarPago(pago))
    {
        cout << "+-------------------------------------------------+" << endl;
        cout << "|         --- Pago realizado con exito ---        |" << endl;
        cout << "|     Proxima fecha de vencimiendo: " << periodo.toString() << "     |" << endl;
        cout << "+-------------------------------------------------+" << endl;
    }
    else
    {
        cout << " --- No se pudo realizar el pago, intente mas tarde --- " << endl;
    }

    system("pause");
}

void ServicioPago::verPago(int idSocio)
{

    system("cls");
    RegistroPago pago;
    int* vPagos;

    int cantPagos = _archivoPago.getCantidadPagos();
    int cantPagosSocio = _archivoPago.cantidadPagosXSocio(cantPagos, idSocio);

    if (cantPagos > 0)
    {
        vPagos = new int[cantPagosSocio];
        *vPagos = _archivoPago.leerPagosXSocio(cantPagos, vPagos, cantPagosSocio, idSocio);

        for (int i = 0; i < cantPagosSocio; i++)
        {
            pago = _archivoPago.leerPago(vPagos[i]);

            cout << "+--------------------------+" << endl;
            cout << "| ID #" << pago.getIdUsuario() << "           |" << endl;
            cout << "| Fecha de pago: " << pago.getFechaPago().toString() << " |" << endl;
            cout << "| Monto: $" << pago.getMonto() << "     |" << endl;
            cout << "+--------------------------+" << endl;
        }
        delete[]vPagos;
    }
    else
    {
        cout << "+-------------------------+" << endl;
        cout << "|  No se registran pagos  |" << endl;
        cout << "+-------------------------+" << endl;
    }

    //delete[]vPagos;
    system("pause");
}

void ServicioPago::listarTotalPagos()
{

    system("cls");
    RegistroPago* vPagos;

    int cantPagos = _archivoPago.getCantidadPagos();
    vPagos = new RegistroPago[cantPagos];

    if (cantPagos > 0)
    {
        for (int i = 0; i < cantPagos; i++)
        {
            _archivoPago.leerTodosPagos(vPagos, cantPagos);

            cout << "+--------------------------+" << endl;
            cout << "| ID #" << vPagos[i].getIdUsuario() << "           |" << endl;
            cout << "| Fecha de pago: " << vPagos[i].getFechaPago().toString() << " |" << endl;
            cout << "| Monto: $" << vPagos[i].getMonto() << "     |" << endl;
            cout << "+--------------------------+" << endl;
        }
    }
    else
    {
        cout << "+-------------------------+" << endl;
        cout << "|  No se registran pagos  |" << endl;
        cout << "+-------------------------+" << endl;
    }

    system("pause");
}

void ServicioPago::verPagosPorMes()
{
    system("cls");

    RegistroPago pago;
    int mes, anio, contador = 0;
    //float contDinero = 0;

    cout << "---------------------------" << endl;
    cout << " Ingrese Anio: ";
    cin >> anio;
    cout << " Ingrese mes: ";
    cin >> mes;

    int cantPagos = _archivoPago.getCantidadPagos();
    //RegistroPago *pagos;
    //pagos = new RegistroPago[cantPagos];

    for (int i = 0; i < cantPagos; i++)
    {
        pago = _archivoPago.leerPago(i);

        if (pago.getFechaPago().getAnio() == anio && pago.getFechaPago().getMes() == mes)
        {
            system("cls");
            cout << "+----------------------------------------------------+" << endl;
            cout << "|                                                    |" << endl;
            cout << "| ID Socio: #" << pago.getIdUsuario() << endl;
            cout << "| Fecha: " << pago.getFechaPago().toString() << endl;
            cout << "| Monto: $" << pago.getMonto() << endl;
            cout << "|                                                    |" << endl;
            cout << "+----------------------------------------------------+" << endl;

            contador++;
            //contDinero += pago.getMonto();
        }
    }

    //cout << "+----------------------------------------------------+" << endl;
    //cout << "|                                                    |" << endl;
    //cout << "| Dinero registrado en el mes " << mes << " " << anio << " " << "es de: " << contDinero << "  |" << endl;
    //cout << "|                                                    |" << endl;
    //cout << "+----------------------------------------------------+" << endl;


    if (contador == 0)
    {
        cout << "+------------------------------------+" << endl;
        cout << "|  No hubo pagos en el mes ingresado |" << endl;
        cout << "+------------------------------------+" << endl;
    }

    system("pause");
}

void ServicioPago::verPagosPorAnio()
{

    system("cls");
    RegistroPago pago;
    int mes, anio;

    int contador = 0;

    cout << "---------------------------" << endl;
    cout << " Ingrese Anio: ";
    cin >> anio;

    int cantidad = _archivoPago.getCantidadPagos();

    for (int i = 0; i < cantidad; i++)
    {
        pago = _archivoPago.leerPago(i);

        if (pago.getFechaPago().getAnio() == anio)
        {
            system("cls");
            cout << "-------------------------------------------" << endl;
            cout << " ID Socio: #" << pago.getIdUsuario() << endl;
            cout << " Fecha: " << pago.getFechaPago().toString() << endl;
            cout << " Monto: $" << pago.getMonto() << endl;

            contador++;
        }

    }

    if (contador == 0)
    {
        cout << "No se econtraron registros..." << endl;
    }

    system("pause");
}

void ServicioPago::verIngresosAnuales()
{

    system("cls");
    RegistroPago pago;

    float vectorMeses[12] {};
    float total = 0;

    int anio;

    int contador = 0;

    cout << "------------------------------------" << endl;
    cout << " Ingrese Anio de consulta: ";
    cin >> anio;

    int cantidad = _archivoPago.getCantidadPagos();

    for (int i = 0; i < cantidad; i++)
    {
        pago = _archivoPago.leerPago(i);

        if (pago.getFechaPago().getAnio() == anio)
        {
            vectorMeses[pago.getFechaPago().getMes() - 1] += pago.getMonto();
            total += pago.getMonto();
            contador++;
        }
    }
    if (contador == 0)
    {
        system("cls");
        cout << "No se econtraron registros..." << endl;
        system("pause");
        return;
    }

    cout << "------------------------------------" << endl;
    cout << " MES             ||       INGRESOS" << endl;
    cout << "------------------------------------" << endl;
    for (int i = 0; i < 12; i++)
    {
        if (vectorMeses[i] != 0)
        {
            switch (i)
            {
            case 0:
                cout << " ENERO           ||   $" << vectorMeses[i] << endl;
                break;
            case 1:
                cout << " FEBRERO         ||   $" << vectorMeses[i] << endl;
                break;
            case 2:
                cout << " MARZO           ||   $" << vectorMeses[i] << endl;
                break;
            case 3:
                cout << " ABRIL           ||   $" << vectorMeses[i] << endl;
                break;
            case 4:
                cout << " MAYO            ||   $" << vectorMeses[i] << endl;
                break;
            case 5:
                cout << " JUNIO           ||   $" << vectorMeses[i] << endl;
                break;
            case 6:
                cout << " JULIO           ||   $" << vectorMeses[i] << endl;
                break;
            case 7:
                cout << " AGOSTO          ||   $" << vectorMeses[i] << endl;
                break;
            case 8:
                cout << " SEPTIEMBRE      ||   $" << vectorMeses[i] << endl;
                break;
            case 9:
                cout << " OCTUBRE         ||   $" << vectorMeses[i] << endl;
                break;
            case 10:
                cout << " NOVIEMBRE       ||   $" << vectorMeses[i] << endl;
                break;
            case 11:
                cout << " DICIEMBRE       ||   $" << vectorMeses[i] << endl;
                break;
            }
        }

    }
    cout << "------------------------------------" << endl;
    cout << " TOTAL ACUMULADO: " << total << endl;
    cout << "------------------------------------" << endl;

    system("pause");
}

void ServicioPago::verIngresosMensuales()
{

    system("cls");
    RegistroPago pago;
    int mes, anio;

    float montoTotal = 0;

    int contador = 0;

    cout << "---------------------------" << endl;
    cout << " Ingrese Anio: ";
    cin >> anio;
    cout << " Ingrese mes: ";
    cin >> mes;

    int cantidad = _archivoPago.getCantidadPagos();

    for (int i = 0; i < cantidad; i++)
    {
        pago = _archivoPago.leerPago(i);

        if (pago.getFechaPago().getAnio() == anio && pago.getFechaPago().getMes() == mes)
        {
            montoTotal += pago.getMonto();
            contador++;
        }
    }

    if (contador == 0)
    {
        system("cls");
        cout << "No se econtraron registros..." << endl;
        system("pause");
        return;
    }

    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << " MES: " << mes << " || INGRESOS: $" << montoTotal << endl;
    cout << "--------------------------------------------" << endl;

    system("pause");
}
