#pragma once

#include "usuarioAutenticado.h"
#include "Usuario.h"


class Autenticador
{

public:

    UsuarioAutenticado autenticar();

private:

    Usuario buscarUsuario(const int idUsuario, const char* pass);
};
