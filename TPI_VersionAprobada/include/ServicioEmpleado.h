#pragma once

#include "GestionArchivoEmpleados.h"

class ServicioEmpleado
{
    public:
        ServicioEmpleado();

        void agregarEmpleado(int idRol);

        void verEmpleados(int idRol);

        void restaurarUnEmpleado(int idRol);

        void modificarEmpleado(int idRol);

        void verSociosAsignados();

        void asignarHorarios();

        void verHorariosAsignados(int idUsuario);

        void modificarContrasenia(int idEmpleado);

        int obternerUltimoIdEmpleado();
        int obternerUltimoId();
        int obternerUltimoLegajo();

        void buscarUnEmpleado(int idRol);

        int seleccionarEntrenador();

        int comprobarDniEmpleado(int dni);

    private:

        GestionArchivoEmpleados _archivoEmpleado;
};

