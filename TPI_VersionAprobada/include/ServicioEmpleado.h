#pragma once

#include "GestionArchivoEmpleados.h"

class ServicioEmpleado
{
    public:
        ServicioEmpleado();

        ///Necesitamos ambos por que entrenador necesita consultar actividades (podria ser sobrecarga)
        void agregarGerenete();
        void agregarEntrenador();

        void verEntrenadores();
        void verGerentes();

        void modificarEmpleado();
        void verSociosAsignados();
        void asignarHorarios();
        void verHorariosAsignados();
        void modificarContrasenia(int idEmpleado);

        ///Para verificar datos de login
        bool buscarEmpleadoLogin(int idSocio, std::string pass);

    private:

        GestionArchivoEmpleados _archivoEmpleado;
};

