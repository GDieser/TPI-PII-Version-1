#include <iostream>
#include "ServicioPago.h"
#include "RegistroPago.h"
#include "GestionArchivoPagos.h"
#include "ServicioPago.h"

using namespace std;

ServicioPago::ServicioPago()
{
    _archivoPago = GestionArchivoPagos("archivoPagos.dat");
}

void ServicioPago::verRegistroPagosPorSocio(int idSocio)
{
    system("cls");


    system("pause");
}

void ServicioPago::registrarPago(int idSocio, int idMembresia, Fecha periodo)
{
    system("cls");


    system("pause");
}

void ServicioPago::verRegistroPagosPorMes()
{
    system("cls");


    system("pause");
}

void ServicioPago::verRegistroPagosPorAnio()
{
    system("cls");


    system("pause");
}

void ServicioPago::verIngresosAnuales()
{
    system("cls");

    GestionArchivoPagos ap;
    RegistroPago rp;

    int cantPagos = ap.getCantRegistros();
    RegistroPago* pagos;
    pagos = new RegistroPago[cantPagos];

    ap.leerTodosReg(pagos, cantPagos);

    float totalAnual = 0.0;
    for (int i = 0; i < cantPagos; i++)
    {
        if (pagos[i].getIdUsuario() == idSocio && pagos[i].getPeriodo().getAnio() == anio) {
            totalAnual += pagos[i].getMonto();
        }
    }

    std::cout << "Id Socio Nro: " << idSocio << std::endl;
    std::cout << "Monto anual: " << totalAnual << std::endl;

    system("pause");

}
void ServicioPago::verIngresosMensuales()
{
    system("cls");

    ArchivoPago ap;
	RegistroPago rp;

	int cantPagos = ap.getCantRegistros();
	RegistroPago *pagos;
	pagos = new RegistroPago[cantPagos];

	ap.leerTodosReg(pagos, cantPagos);

	float totalMensual = 0.0;
	for (int i = 0; i < cantPagos; i++) {

		if (pagos[i].getIdUsuario() == idSocio && pagos[i].getPeriodo().getMes() == mes) {
			totalMensual += pagos[i].getMonto();
		}
	}

	std::cout << "Id Socio Nro: " << idSocio << std::endl;
	std::cout << "Monto mensual: " << totalMensual << std::endl;

    system("pause");

}
