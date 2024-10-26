#pragma once


class MenuPrincipal
{
public:
    MenuPrincipal();

    void mostrarMenuInicio();
    void mostrarMenuLogin(int &idUsuario, std::string &pass);
    bool verificarLoginSocio(int &idUsuario, std::string &pass);
    bool verificarLoginEmpleado(int &idUsuario, std::string &pass);

    bool mostrarSubmenuSocio(int &idUsuario, std::string &pass);
    bool mostrarMenuIngresoSocio();

protected:

    int _opcion;
};

