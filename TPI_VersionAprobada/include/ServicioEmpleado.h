#pragma once

#include "GestionArchivoEmpleados.h"

class ServicioEmpleado
{
    public:
        ServicioEmpleado();

        void agregarGerente();
        void agregarEntrenador();

        void verEntrenadores();
        void verGerentes();

        void modificarEmpleado();
        void verSociosAsignados();
        void asignarHorarios();
        void verHorariosAsignados();
        void modificarContrasenia(int idEmpleado);

        int obternerUltimoIdEmpleado();
        int obternerUltimoId();
        int obternerUltimoLegajo();

        bool buscarUnEmpleado(int idEmpleado);

    private:

        GestionArchivoEmpleados _archivoEmpleado;
};

