#include <iostream>

#include "DetalleRutina.h"

using namespace std;

DetalleRutina::DetalleRutina()
{
    //ctor
}

DetalleRutina::DetalleRutina(int *idEjercicios, int idRutina, int *repeticiones,  float *peso)
{

    setIdEjercicios(idEjercicios);
    setRepeticiones(repeticiones);
    setPeso(peso);

    setIdRutina(idRutina);
}

int* DetalleRutina::getIdEjercicios()
{
    return _idEjercicios;
}
int DetalleRutina::getIdRutina()
{
    return _idRutina;
}
int* DetalleRutina::getRepeticiones()
{
    return _repeticiones;
}
float* DetalleRutina::getPeso()
{
    return _peso;
}

void DetalleRutina::setIdEjercicios(int *idEjercicios)
{

    for(int i=0; i<10; i++)
    {
        _idEjercicios[i] = idEjercicios[i];
    }

}
void DetalleRutina::setIdRutina(int idRutina)
{
    _idRutina = idRutina;
}

void DetalleRutina::setRepeticiones(int *repeticiones)
{
    for(int i=0; i<10; i++)
    {
        _repeticiones[i] = repeticiones[i];
    }
}

void DetalleRutina::setPeso(float *peso)
{
    for(int i=0; i<10; i++)
    {
        _peso[i] = peso[i];
    }
}
