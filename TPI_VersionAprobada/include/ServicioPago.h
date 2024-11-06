#pragma once

#include "GestionArchivoPagos.h"

class ServicioPago
{
    private:
        GestionArchivoPagos _archivoPago;

    public:
        ServicioPago();

        bool verificarUltimoPago(int idSocio);
        void registrarPago(int idSocio, int idMembresia, Fecha periodo);
        void verPago(int idSocio);
        void listarTotalPagos();
        void verPagosPorMes();
        void verPagosPorAnio();
        void verIngresosAnuales();
        void verIngresosMensuales();
};

