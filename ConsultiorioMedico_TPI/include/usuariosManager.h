#pragma once
#include "usuariosArchivo.h"


class UsuariosManager
{
public:
    void crearAdminSiNoExiste();
    void altaUsuario();
    void bajaUsuario();
    void listarUsuarios();
    Usuarios login();



    int numeroRol (const char* rol);


protected:

private:

    UsuariosArchivo _repoUsuarios;

};

