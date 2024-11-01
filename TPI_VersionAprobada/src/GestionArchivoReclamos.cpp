#include <iostream>

#include "GestionArchivoReclamos.h"

using namespace std;

GestionArchivoReclamos::GestionArchivoReclamos()
{

}

GestionArchivoReclamos::GestionArchivoReclamos(string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

bool GestionArchivoReclamos::guardarReclamo(const Reclamo& r) {

	FILE* pfile;
	pfile = fopen(_nombreArchivo.c_str(), "ab");
	if (pfile == nullptr) {
		std::cout << " ->- No se pudo abrir el archivo -<- ";
		return false;
	}

	bool result = fwrite(&r, sizeof(Reclamo), 1, pfile) == 1;
	fclose(pfile);

	return result;
}

Reclamo GestionArchivoReclamos::leerReclamo(int pos) {

	Reclamo r;
	FILE* pfile;
	pfile = fopen(_nombreArchivo.c_str(), "rb");
	if (pfile == nullptr)
	{
		std::cout << " ->- No se pudo abrir el archivo -<- ";
		return r;
	}

	fseek(pfile, 0, SEEK_SET);
	fread(&r, sizeof(Reclamo) * pos, 1, pfile);
	fclose(pfile);

	return r;
}

int GestionArchivoReclamos::getCantidadReclamos() {

	int totalBytes, cantReg;
	Reclamo r;
	FILE *pfile;
	pfile = fopen(_nombreArchivo.c_str(), "rb");
	if (pfile == nullptr)
	{
		std::cout << " ->- No se pudo abrir el archivo -<- ";
		return 0;
	}

	fseek(pfile, 0, SEEK_END);

	totalBytes = ftell(pfile);

	return cantReg = totalBytes / sizeof(Reclamo);
}

bool GestionArchivoReclamos::leerTodosReclamos(Reclamo r[], int cantReclamos) {

	FILE* pfile;
	pfile = fopen(_nombreArchivo.c_str(), "rb");

	if (pfile == nullptr) {
		std::cout << " ->- No se pudo abrir el archivo -<- ";
		return false;
	}

	bool result = fread(r, sizeof(Reclamo), cantReclamos, pfile) == 1;
	fclose(pfile);

	return result;
}

bool GestionArchivoReclamos::modificarReclamo(Reclamo &r, int pos)

	FILE* pfile;
	bool result;

	pfile = fopen(_nombreArchivo.c_str(), "rb+");
	if (pfile == nullptr) {
		std::cout << " ->- No se pudo abrir el archivo -<- ";
		return false;
	}

	fseek(pfile, pos, SEEK_SET);

	result = fwrite(&r, sizeof(Reclamo), 1, pfile) == 1;

	fclose(pfile);
	return result;
}

int GestionArchivoReclamos::buscarReclamo(int id) {

	Reclamo r;
	int pos = 0;
	FILE *pfile;
	pfile = fopen(_nombreArchivo.c_str(), "rb");
	if (pfile == nullptr) {
		std::cout << " ->- No se pudo abrir el archivo -<- ";
		return 0;
	}

	while (fread(&r, sizeof(Reclamo), 1, pfile) == 1)
	{
		if (r.getIdReclamo() == id) {
			break;
		}
		pos++;
	}

	fclose(pfile);

	if (r.getIdReclamo() == id) {
		return pos;
	}
	else {
		return -1;
	}
}


void GestionArchivoReclamos::leerRegistrosReclamo(int cantidadRegistros, Reclamo *vecReclamo){
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return;
    }

    for(int i = 0; i < cantidadRegistros; i++)
    {
        fread(&vecReclamo[i], sizeof(Reclamo), 1, pArchivo);
    }

    fclose(pArchivo);
}

int GestionArchivoReclamos::cantidadDeRegistrosPorUsuario(int cantidadRegistros, int idUsuario){
    int cont = 0;
    FILE *pArchivo;

    Reclamo reclamo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return -1;
    }

    for(int i=0; i<cantidadRegistros; i++)
    {
        fread(&reclamo, sizeof(Reclamo), 1, pArchivo);
        if(reclamo.getIdUsuario() == idUsuario)
        {
            cont++;
        }
    }

    fclose(pArchivo);

    return cont;

}

int GestionArchivoReclamos::leerRegistrosPorUsuario(int cantidadRegistros, int vectReclamos[], int tam, int idUsuario){
    int cont = 0, indice = 0;
    FILE *pArchivo;

    Reclamo reclamo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return -1;
    }

    for(int i=0; i<cantidadRegistros; i++)
    {
        fread(&reclamo, sizeof(Reclamo), 1, pArchivo);
        if(reclamo.getIdUsuario() == idUsuario)
        {
            vectReclamos[indice] = i;
            indice++;
        }
    }

    fclose(pArchivo);

    return *vectReclamos;
}


