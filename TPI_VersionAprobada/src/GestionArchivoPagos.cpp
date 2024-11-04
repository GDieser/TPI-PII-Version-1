#include <iostream>

#include "GestionArchivoPagos.h"

using namespace std;

GestionArchivoPagos::GestionArchivoPagos() {}

GestionArchivoPagos::GestionArchivoPagos(std::string nombreArchivo) {
	_nombreArchivo = nombreArchivo;
}

bool GestionArchivoPagos::guardarPago(const RegistroPago& rp) {

	FILE* pfile;
	pfile = fopen(_nombreArchivo.c_str(), "ab");
	if (pfile == nullptr) {
		std::cout << " ->- No se pudo abrir el archivo -<- ";
		return false;
	}

	bool result = fwrite(&rp, sizeof(RegistroPago), 1, pfile) == 1;
	fclose(pfile);

	return result;
}

bool GestionArchivoPagos::modificarPago(RegistroPago& rp, int pos) {

	FILE* pfile;
	bool result;

	pfile = fopen(_nombreArchivo.c_str(), "rb+");
	if (pfile == nullptr) {
		std::cout << " ->- No se pudo abrir el archivo -<- ";
		return false;
	}

	fseek(pfile, pos, SEEK_SET);

	result = fwrite(&rp, sizeof(RegistroPago), 1, pfile) == 1;

	fclose(pfile);
	return result;
}

RegistroPago GestionArchivoPagos::leerPago(int pos) {

	RegistroPago rp;
	FILE* pfile;
	pfile = fopen(_nombreArchivo.c_str(), "rb");
	if (pfile == nullptr)
	{
		std::cout << " ->- No se pudo abrir el archivo -<- ";
		return rp;
	}

	fseek(pfile, 0, SEEK_SET);
	fread(&rp, sizeof(RegistroPago) * pos, 1, pfile);
	fclose(pfile);

	return rp;
}

int GestionArchivoPagos::getCantidadPagos() {

	int totalBytes, cantReg;
	RegistroPago rp;
	FILE* pfile;
	pfile = fopen(_nombreArchivo.c_str(), "rb");
	if (pfile == nullptr)
	{
		std::cout << " ->- No se pudo abrir el archivo -<- ";
		return 0;
	}

	fseek(pfile, 0, SEEK_END);

	totalBytes = ftell(pfile);

	return cantReg = totalBytes / sizeof(RegistroPago);
}

void GestionArchivoPagos::leerTodosPagos(RegistroPago *vPagos, int cantPagos) {

	FILE* pfile;
	pfile = fopen(_nombreArchivo.c_str(), "rb");

	if (pfile == nullptr) {
		std::cout << " ->- No se pudo abrir el archivo -<- ";
		return;
	}

	for (int i = 0; i < cantPagos; i++)
	{
		fread(&vPagos[i], sizeof(RegistroPago), cantPagos, pfile);
	}

	fclose(pfile);
}

int GestionArchivoPagos::buscarPago(int id) {

	RegistroPago rp;
	int pos = 0;
	FILE* pfile;
	pfile = fopen(_nombreArchivo.c_str(), "rb");
	if (pfile == nullptr) {
		std::cout << " ->- No se pudo abrir el archivo -<- ";
		return 0;
	}

	while (fread(&rp, sizeof(RegistroPago), 1, pfile) == 1)
	{
		if (rp.getIdUsuario() == id) {
			break;
			//return pos;
		}
		pos++;
	}

	fclose(pfile);

	if (rp.getIdUsuario() == id) { // dos posibilidades, o que haya llegado al final porque lo encontro e hizo el break o porque trato de leer y no pudo
		return pos;
	}
	else { // no lo encontro
		return -1;
	}
}

int GestionArchivoPagos::cantidadPagosXSocio(int cantPagos, int idUsuario) {

	RegistroPago pago; // es la clase pago

	int cont = 0;
	FILE* pfile;
	pfile = fopen(_nombreArchivo.c_str(), "rb");

	if (pfile == nullptr) {	return -1; }

	for (int i = 0; i < cantPagos; i++)
	{
		fread(&pago, sizeof(RegistroPago), 1, pfile);
		if (pago.getIdUsuario() == idUsuario)
		{
			cont++;
		}
	}

	fclose(pfile);
	return cont;
}

int GestionArchivoPagos::leerPagosXSocio(int cantPagos, int vPagos[], int tam, int idUsuario) {

	RegistroPago pago; // es la clase pago

	int cont = 0, index = 0;
	FILE* pfile;
	pfile = fopen(_nombreArchivo.c_str(), "rb");

	if (pfile == nullptr) { return -1; }

	for (int i = 0; i < cantPagos; i++)
	{
		fread(&pago, sizeof(RegistroPago), 1, pfile);
		if (pago.getIdUsuario() == idUsuario)
		{
			vPagos[index] = i;
			index++;
		}
	}

	fclose(pfile);
	return *vPagos;
}

int GestionArchivoPagos::ultimoPagoSocio(int cantPagos, int idUsuario) {

    RegistroPago pago;

	int pos = -1;
    FILE *pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

	if (pArchivo == nullptr) { return -1; }

    for(int i = 0; i < cantPagos; i++)
    {
        fread(&pago, sizeof(RegistroPago), 1, pArchivo);
        if(pago.getIdUsuario() == idUsuario)
        {
            pos = i;
        }
    }

    fclose(pArchivo);

    return pos;
}
