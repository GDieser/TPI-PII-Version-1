#include <iostream>

#include "RegistroPago.h"

using namespace std;


RegistroPago::RegistroPago()
{
    //ctor
}

RegistroPago::RegistroPago(int idUsuario, float monto, Fecha periodo, Fecha fechaPago)
{
    setIdUsuario(idUsuario);
    setMonto(monto);
    setPeriodo(periodo);
    setFechaPago(fechaPago);
}

int RegistroPago::getIdUsuario()
{
    return _idUsuario;
}
float RegistroPago::getMonto()
{
    return _monto;
}
Fecha RegistroPago::getPeriodo()
{
    return _periodo;
}
Fecha RegistroPago::getFechaPago()
{
    return _fechaPago;
}

void RegistroPago::setIdUsuario(int idUsuario)
{
    _idUsuario = idUsuario;
}
void RegistroPago::setMonto(float monto)
{
    _monto = monto;
}
void RegistroPago::setPeriodo(Fecha periodo)
{
    _periodo = periodo;
}
void RegistroPago::setFechaPago(Fecha fechaPago)
{
    _fechaPago = fechaPago;
}
