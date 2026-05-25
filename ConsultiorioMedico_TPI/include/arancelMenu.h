#pragma once
#include "arancelManager.h"
#include "menu.h"

class ArancelMenu: public Menu {
public:
   ArancelMenu();
   void mostrarOpciones();
   void ejecutarOpcion(int opcion);

private:
   arancelManager _managerArancel;
};
