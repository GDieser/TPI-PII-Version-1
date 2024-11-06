#pragma once

#include "Socio.h"

class GestionArchivoSocios
{
    public:

        GestionArchivoSocios();

        GestionArchivoSocios(std::string nombreArchivo);

        bool guardarSocio(Socio socio);
        bool guardarSocio(Socio socio, int posicion);
        int buscarSocio(int idSocio);
        Socio leerRegistroSocio(int posicion);
        int cantidadRegistrosSocios();
        void leerRegistrosSocios(int cantidadRegistros, Socio *vecSocio);
:

    private:
        std::string _nombreArchivo;
};
