#pragma once
#include "usuariosArchivo.h"


class UsuariosManager
{
public:
    void altaUsuario();
    void bajaUsuario();
    void listarUsuarios();
    int login();

    int numeroRol (const char* rol);


protected:

private:

    UsuariosArchivo _repoUsuarios;
};

