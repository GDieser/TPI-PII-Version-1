#pragma once

#include "RegistroPago.h"


class GestionArchivoPagos
{
    private:
        std::string _nombreArchivo;

    public:
        GestionArchivoPagos();
        GestionArchivoPagos(std::string nombreArchivo);
        bool guardarPago(const RegistroPago &p);
        RegistroPago leerPago(int pos);
        bool modificarPago(RegistroPago &p, int pos);
        void leerTodosPagos(RegistroPago *p, int);
        int getCantidadPagos();
        int buscarPago(int idUsuario);

        /// filtros por socio
        int cantidadPagosXSocio(int cantidadRegistros, int idUsuario);
        int leerPagosXSocio(int cantidadRegistros, int vectPagos[], int tam, int idUsuario);
        int ultimoPagoSocio(int cantidadRegistros, int idUsuario);
};
