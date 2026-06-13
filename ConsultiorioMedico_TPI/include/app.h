#pragma once
#include "menu.h"
#include "usuariosManager.h"
#include "menuAdministrador.h"
#include "menuMedico.h"
#include "menuRecepcionista.h"

class App: public Menu {
public:
   App();
   void mostrarOpciones() override;
   int seleccionarOpcion() ;
   void ejecutarOpcion(int opcion) override;

private:
    UsuariosManager _usuarioManager;
    Usuarios _usuario;

    MenuRecepcionista _menuRecepcionista;
    MenuMedico _menuMedico;
    MenuAdministrador _menuAdministrador;
};
