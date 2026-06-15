#pragma once
#include "usuariosArchivo.h"
#include "medicosManager.h"
#include "medicosArchivo.h"


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
    MedicosArchivos _repoMedicos;

};

