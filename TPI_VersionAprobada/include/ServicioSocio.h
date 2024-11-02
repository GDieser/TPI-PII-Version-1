#pragma once

#include "GestionArchivoSocios.h"

class ServicioSocio
{
public:

    ServicioSocio();

    void verSocios();
    void agregarSocio();
    void modificarSocio();
    void verEntrenadorAsignado(int idSocio);
    void verHorarios();
    void verMembresia(int idSocio);
    void modificarContrasenia(int idSocio);

    ///Necesario para login en el menu
    bool buscarSocioLogin(int idSocio, std::string pass);

    ///Necesario para login en el gimanasio y registrar asistencia
    bool validarLoginAsistenciaSocio(int idSocio, int pin);

    int obternerUltimoIdSocio();


private:

    GestionArchivoSocios  _archivoSocio;
};


