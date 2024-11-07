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

bool Fecha::esBisiesto(int anio)
{
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

int Fecha::diasPorMes(int mes, int anio)
{
    int diasPorMeses[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (mes == 2 && esBisiesto(anio))
    {
        return 29;
    }
    else
    {
        return diasPorMeses[mes - 1];
    }
}

bool Fecha::validarDia()
{
    return _dia >= 1 && _dia <= diasPorMes(_mes, _anio);
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

Fecha Fecha::crearFecha()
{
    int dia, mes, anio;
    cout << "Ingrese dia: ";
    cin >> dia;
    cout << "Ingrese mes: ";
    cin >> mes;
    cout << "Ingrese anio: ";
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
    return (_anio == fecha.getAnio() && _mes == fecha.getMes() && _dia == fecha.getDia());
}


Fecha Fecha::sumarDiasParaVencimiento(Fecha fechaVencimiento)
{
    int dia = fechaVencimiento.getDia() + 35;
    int mes = fechaVencimiento.getMes();
    int anio = fechaVencimiento.getAnio();

    while (dia > diasPorMes(mes, anio))
    {

        dia -= diasPorMes(mes, anio);
        mes++;


        if (mes > 12)
        {
            mes = 1;
            anio++;
        }
    }

    return Fecha(dia, mes, anio);
}
