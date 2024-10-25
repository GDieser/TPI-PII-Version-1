#pragma once

#include "Fecha.h"


class RegistroPago
{
public:

    RegistroPago();
    RegistroPago(int idUsuario, float monto, Fecha periodo, Fecha fechaPago);

    int getIdUsuario();
    float getMonto();
    Fecha getPeriodo();
    Fecha getFechaPago();

    void setIdUsuario(int idUsuario);
    void setMonto(float monto);
    void setPeriodo(Fecha periodo);
    void setFechaPago(Fecha fechaPago);

private:

    int _idUsuario;
    float _monto;
    Fecha _periodo;
    Fecha _fechaPago;
};
