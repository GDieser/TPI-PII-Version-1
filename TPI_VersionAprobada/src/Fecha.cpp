#include <iostream>
#include <ctime>

#include "Fecha.h"

using namespace std;

Fecha::Fecha()
{
    establecerFechaActual();
}

Fecha::Fecha(int dia, int mes, int anio)
{
    setDia(dia);
    setMes(mes);
    setAnio(anio);

    validarFecha();
}

int Fecha::getDia() const
{
    return _dia;
}

int Fecha::getMes() const
{
    return _mes;
}

int Fecha::getAnio() const
{
    return _anio;
}

void Fecha::setDia(int dia)
{
    _dia = dia;
}

void Fecha::setMes(int mes)
{
    _mes = mes;
}

void Fecha::setAnio(int anio)
{
    _anio = anio;
}

void Fecha::establecerFechaActual()
{
    time_t timestamp = time(0);

    tm *diaActual = localtime(&timestamp);

    _dia = diaActual->tm_mday;

    _mes = diaActual->tm_mon+1;

    _anio = diaActual->tm_year+1900;

}

bool Fecha::validarDia()
{
    int diasPorMeses[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    return _dia >= 1 && _dia <= diasPorMeses[_mes-1];
}

bool Fecha::validarMes()
{
    return _mes >= 1 && _mes <= 12;
}

bool Fecha::validarAnio()
{
    return _anio > 0;
}

void Fecha::validarFecha()
{
    if(!validarDia() || !validarMes() || !validarAnio())
    {
        setFechaDefecto();
    }
}

Fecha Fecha::crearFecha(){
    int dia, mes, anio;
    cout << "Ingrese dia: ";
    cin >> dia;
    cout << "Ingrese mes: ";
    cin >> mes;
    cout << "Ingrese año: ";
    cin >> anio;
    return Fecha(dia, mes, anio);
}

void Fecha::setFechaDefecto()
{
    _dia = 1;
    _mes = 1;
    _anio = 1;
}

string Fecha::toString()
{
    return std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio);
}

bool Fecha::compararSiFechasSonIguales(Fecha fecha)
{
    Fecha fechaActual;

    if(fechaActual.getAnio() == fecha.getAnio() && fechaActual.getMes() == fecha.getMes() && fechaActual.getDia() == fecha.getDia())
    {
        return true;
    }

    return false;
}
