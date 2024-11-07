#pragma once

#include "GestionArchivoSocios.h"
#include "GestionArchivoEmpleados.h"

class ServicioSocio
{
public:

    ServicioSocio();

    void verSocios();
    void verSociosPorApellido();
    void verSociosPorDni();
    void agregarSocio();
    void modificarSocio();
    void verEntrenadorAsignado(int idSocio);
    void verHorarios();
    void verMembresia(int idSocio);
    void modificarContrasenia(int idSocio);
    // Agregados como metodos auxiliares

    int autoGenerarId();
    std::string membresiaToStr(int idMemb);
    int seleccionarMembresia();
    void mostrarTurno(int idTurno);
    Socio buscarSocioId(int idUsuario);
    void mostrarSociosPorEntrenador(int idEntrenador);

    void mostrarFechaVencimiento(Fecha fechaIngreso, int idSocio);
    bool consultarEstadoDeSocio(int idSocio);
    void actualizarEstadoDelSocio(int idSocio, bool estado);
    void buscarSocioPorId();

    bool buscarSocioPorDni(int dni);

    void listarSocios(Socio socios[], int cantReg);



private:

    GestionArchivoSocios  _archivoSocio;
    GestionArchivoEmpleados _archivoEmpleado;
};

