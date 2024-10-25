#pragma once


class DetalleRutina
{
public:
    DetalleRutina();
    DetalleRutina(int *idEjercicios, int idRutina, int *repeticiones, float *peso);

    int* getIdEjercicios();
    int getIdRutina();
    int* getRepeticiones();
    float* getPeso();

    void setIdEjercicios(int *idEjercicios);
    void setIdRutina(int idRutina);
    void setRepeticiones(int *repeticiones);
    void setPeso(float *peso);

private:

    int _idEjercicios[10];
    int _idRutina;
    int _repeticiones[10];
    float _peso[10];
};
