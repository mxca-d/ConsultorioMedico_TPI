#pragma once
#include "usuariosManager.h"
#include "menu.h"

class UsuarioMenu: public Menu {
public:
   UsuarioMenu();
   void mostrarOpciones();
   void ejecutarOpcion(int opcion);

private:
   UsuariosManager _managerUsuario;
};
