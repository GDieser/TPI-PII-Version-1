#pragma once

#include "GestionArchivoPagos.h"

class ServicioPago
{
    public:
        ServicioPago();

        ///Ya que pago es solo para socios ahora
        void verRegistroPagosPorSocio(int idSocio);

        void registrarPago(int idSocio, int idMembresia, Fecha periodo);
        void verIngresosAnuales();
        void verIngresosMensuales();

        ///Vamos a necesitar para las listas del informe
        void verRegistroPagosPorMes();
        void verRegistroPagosPorAnio();

    private:

        GestionArchivoPagos _archivoPago;
};

