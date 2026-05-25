#pragma once
#include "historialManager.h"
#include "menu.h"

class HistorialMenu: public Menu {
public:
   HistorialMenu();
   void mostrarOpciones();
   void ejecutarOpcion(int opcion);

private:
   HistorialManager _managerHistorial;
};
