#pragma once
#include "obraSocialManager.h"
#include "menu.h"

class ObraSocialMenu: public Menu {
public:
   ObraSocialMenu();
   void mostrarOpciones();
   void ejecutarOpcion(int opcion);

private:
   ObraSocialManager _managerObraSocial;
};
